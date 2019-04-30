#ifndef BORROW_H_
#define BORROW_H_

#include "book.h" // File quan ly sach

// File luu danh sach phieu muon
#define BORROW_FILE "./Data/Borrows.bin"

// File luu tam
#define TEMP_BORROW_FILE "./Data/Borrows_temp.bin"

#define LENGTH_BORROW_ID 7        // Ma phieu muon sach co 6 ky tu
#define LENGTH_PERSON_ID 7        // Ma so nguoi muon co 6 ky tu
#define LENGTH_PERSON_NAME 31     // Ten nguoi muon sach toi da 30 ky tu
#define LENGTH_BOOK_ID 7          // Ma sacu co 6 ky tu
#define LENGTH_BOOK_TITLE 51      // Tieu de sach toi da 50 ky tu
#define LENGTH_DAY_BORROWED 11    // Ngay muon co 10 ku tu
#define LENGTH_BOOK_STATUS 12     // Tinh trang sach
#define LENGTH_DAY_RETURN 11      // Ngay muou co 10 ku tu
#define LENGTH_BORROWED_STATUS 10 // Trang thai phieu muon (Dang muon/Da tra)

class Borrow
{
private:
  char borrow_id_[LENGTH_BORROW_ID];              // Ma phieu muon
  char person_id_[LENGTH_PERSON_ID];              // Ma nguoi muon
  char person_name_[LENGTH_PERSON_NAME];          // Ten nguoi muon
  char book_id_[LENGTH_BOOK_ID];                  // Ma sach
  char book_title_[LENGTH_BOOK_TITLE];            // Tieu de sach
  char day_borrowed_[LENGTH_DAY_BORROWED];        // Ngay muon
  char day_returned_[LENGTH_DAY_RETURN];          // Ngay tra
  char status_borrowed_book_[LENGTH_BOOK_STATUS]; // Tinh trang sach khi muon
  char status_returned_book_[LENGTH_BOOK_STATUS]; // Tinh trang sach khi tra
  char borrow_status_[LENGTH_BORROWED_STATUS];    // Trang thai phieu muon (Dang
                                                  // muon/Da tra)
public:
  // Ham khoi tao khong tham so
  Borrow();

  // Ham khoi tao co tham so
  Borrow(char *, char *, char *, char *, char *, char *, char *, char *, char *,
         char *);

  // Ham huy
  ~Borrow();

  //----------------------------------------------------------------------//

  // Gan gia tri cho ma phieu
  void set_borrow_id(string);

  // Tra ve ma phieu
  string get_borrow_id();

  // Gan gia tri cho ma nguoi muon
  void set_person_id(string);

  // Tra ve ma nguoi muon
  string get_person_id();

  // Gan gia tri cho ten nguoi muon
  void set_person_name(string);

  // Tra ve ten nguoi muon
  string get_person_name();

  // Gan gia tri ma sach
  void set_book_id(string);

  // Tra ve ma sach
  string get_book_id();

  // Gan gia tri cho tieu de sach
  void set_book_title(string);

  // Tra ve tieu de sach
  string get_book_title();

  // Gan gia tri cho ngay muon sach
  void set_day_borrowed(string);

  // Tra ve ngay muon sach
  string get_day_borrowed();

 // Tra ve ngay muon sach de sap xep danh sach theo ngay muon
  string get_year();

  // Gan gia tri cho ngay tra sach
  void set_day_returned(string);

  // Tra ve ngay tra sach
  string get_day_returned();

  // Gan gia tri cho tinh trang sach khi muon
  void set_status_borrowed_book(string);

  // Tra ve tinh trang sach khi muon
  string get_status_borrowed_book();

  // Gan gia tri cho tinh trang sach khi tra
  void set_status_returned_book(string);

  // Tra ve gia tri tinh trang sach khi tra
  string get_status_returned_book();

  // Gan gia tri cho trang thai phieu muon
  void set_borrow_status(string);

  // Tra ve trang thai phieu muon
  string get_borrow_status();

  //----------------------------------------------------------------------//

  // Nhap thong tin phieu muon sach
  virtual void input_an_info();

  // Nhap thong tin phieu tra sach
  void input_return();

  // Xuat thong tin phieu dang muon chua tra
  void display_borrowing(int);

  // Xuat thong tin phieu muon da tra
  void display_returned(int);

  // Xuat danh sach phieu muon
  void display_borrow_list(list<Borrow>, string);

  // Ghi thong tin phieu muon vao file BORROW_FILE (Danh sach phieu muon)
  void write_borrow_info(list<Borrow>, string);

  // Doc thong tin tu file BORROW_FILE (Danh sach phieu muon)
  void read_borrow_info(list<Borrow> &, string);

  // Hien thi tieu de danh sach phieu dang muon
  void title_borrowing_list();

  // Hien thi tieu de danh sach phieu muon da tra
  void title_returned_list();
};

#endif // BORROW_H_