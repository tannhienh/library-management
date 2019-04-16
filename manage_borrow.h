#ifndef MANAGE_BORROW_H_
#define MANAGE_BORROW_H_

#include "borrow.h"  // File quan ly phieu muon
#include <algorithm> // sort, reverse

// Ghi thong tin sach/phieu muon vua nhap vao file BOOK_FILE/BORROW_FILE
template <typename container>
void write_info_to_file(container contain, string file_name) {
  ofstream out_file;
  try {
    out_file.open(file_name, ios::app | ios::binary);
    if (!out_file)
      throw "  Loi mo file ";
    // Luu thong tin da nhap vao file
    out_file.write(reinterpret_cast<char *>(&contain.back()),
                   sizeof(contain.back()));
  } catch (const char *str_error) {
    cout << str_error << file_name << endl;
    return;
  } catch (...) {
    cerr << "  Loi ghi file " << file_name;
  }
  out_file.close();
}

// Nhap thong tin sach/phieu muon
template <typename container, typename T>
void input_info(container &contain, string file_name, T &t) {
  t.input_an_info();    // Goi ham nhap thong tin cho sach/phieu muon
  contain.push_back(t); // Luu thong tin vua nhap vao contain

  // Ghi thong tin vua nhap vao file
  write_info_to_file<container>(contain, file_name);
}

// Doc danh sach sach/phieu muon tu file
// Luu vao contain
template <typename container, typename T>
void read_list_from_file(container &contain, string file_name) {
  ifstream in_file;
  try {
    in_file.open(file_name, ios::app | ios::binary);
    if (!in_file)
      throw "  Loi mo file ";
    T t;
    while (in_file.read(reinterpret_cast<char *>(&t), sizeof(t))) {
      // Luu vao cuoi container contain
      contain.push_back(t);
    }
  } catch (const char *str_error) {
    cout << str_error << file_name << endl;
    return;
  } catch (...) {
    cerr << "  Loi doc file " << file_name;
  }
  in_file.close();
}

// Ghi sanh sach thong tin sach/phieu muon tu container vao file
template <typename container, typename iterator>
void write_list_to_file(container contain, string file_name) {
  ofstream out_file;
  try {
    out_file.open(file_name, ios::app | ios::binary);
    if (!out_file)
      throw "  Loi mo file ";
    // Luu thong tin sach vao file
    iterator it;
    for (it = contain.begin(); it < contain.end(); it++)
      out_file.write(reinterpret_cast<char *>(&*it), sizeof(*it));
  } catch (const char *str_error) {
    cout << str_error << file_name << endl;
    return;
  } catch (...) {
    cerr << "  Loi ghi file " << file_name;
  }
  out_file.close();
}

// Thay doi so luong sach sau khi tao phieu muon hoac tra sach
// Thay doi trong container books
// voi sach co ma sach book_id
// n = 1 khi tra sach thanh cong
// n = -1 khi tao phieu muon thanh cong
// Ghi danh sach sach tu container books
// sau khi thay doi so luong sach thanh cong vao file TEMP_BOOK_FILE
void change_amount(vector<Book> &books, string book_id, int n) {
  vector<Book>::iterator it;
  for (it = books.begin(); it < books.end(); it++)
    if (it->get_book_id() == book_id) {
      it->set_amount(it->get_amount() + n);
      break;
    }
  // Ghi danh sach sach tu container books vao file TEMP_BOOK_FILE
  write_list_to_file<vector<Book>, vector<Book>::iterator>(books,
                                                           TEMP_BOOK_FILE);
  // Xoa file BOOK_FILE cu
  remove(BOOK_FILE);

  // Doi ten file TEMP_BOOK_FILE da thay doi so luong thanh BOOK_FILE
  rename(TEMP_BOOK_FILE, BOOK_FILE);
}

// Thay doi noi dung phieu muon khi tra sach thanh cong gom:
// Gan ngay tra vao phieu muon
// Gan tinh trang sach khi tra vao phieu muon
// Thay doi trang thai phieu muon thanh Da tra
// Gan ma sach da tra tro lai phieu muon da nhap
// de thuc hien tang so luong sach da tra
void change_borrow(vector<Borrow> &borrows, Borrow &borrow) {
  vector<Borrow>::iterator it;
  for (it = borrows.begin(); it < borrows.end(); it++)
    // Neu tim thay dung ma phieu muon thi thuc hien thay doi
    // thong tin phieu muon
    if (it->get_borrow_id() == borrow.get_borrow_id()) {
      // Gan ngay tra vao phieu muon
      it->set_day_returned(borrow.get_day_returned());

      // Gan tinh trang sach khi tra vao phieu muon
      it->set_status_returned_book(borrow.get_status_returned_book());

      // Thay doi trang thai phieu muon thanh Da tra
      it->set_borrow_status(borrow.get_borrow_status());

      // Gan ma sach da tra tro lai phieu muon da nhap
      // de thuc hien tang so luong sach da nhap
      borrow.set_book_id(it->get_book_id());
      break;
    }
  // Ghi danh sach phieu muon da thay doi thong tin cao file TEMP_BORROW_FILE
  write_list_to_file<vector<Borrow>, vector<Borrow>::iterator>(
      borrows, TEMP_BORROW_FILE);

  // Xoa file BORROW_FILE cu
  remove(BORROW_FILE);

  // Doi ten file TEMP_BORROW_FILE da thay doi thong tin phieu muon
  // thanh BORROW_FILE
  rename(TEMP_BORROW_FILE, BORROW_FILE);
}

#endif // MANGE_BORROW_H_