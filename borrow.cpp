#include "borrow.h"

// Ham khoi tao khong co tham so
Borrow::Borrow() {
  strcpy(borrow_id_, "");
  strcpy(person_id_, "");
  strcpy(person_name_, "");
  strcpy(book_id_, "");
  strcpy(book_title_, "");
  strcpy(day_borrowed_, "");
  strcpy(day_returned_, "");
  strcpy(status_borrowed_book_, "");
  strcpy(status_returned_book_, "");
  strcpy(borrow_status_, "");
}

// Ham khoi tao co tham so
Borrow::Borrow(char *Borrow_id, char *person_id, char *person_name,
               char *book_id, char *book_title, char *day_borrowed,
               char *day_returned, char *status_borrowed, char *status_returned,
               char *borrow_status) {
  *borrow_id_ = *Borrow_id;
  *person_id_ = *person_id;
  *person_name_ = *person_name;
  *book_id_ = *book_id;
  *book_title_ = *book_title;
  *day_borrowed_ = *day_borrowed;
  *day_returned_ = *day_returned;
  *status_borrowed_book_ = *status_borrowed;
  *status_returned_book_ = *status_returned;
  *borrow_status_ = *borrow_status;
}

// Ham huy
Borrow::~Borrow() {}

//----------------------------------------------------------------------//

// Gan gia tri cho ma phieu muon
void Borrow::set_borrow_id(string borrow_id) {
  strcpy(borrow_id_, borrow_id.c_str());
}

// Tra ve ma phieu muon
string Borrow::get_borrow_id() { return borrow_id_; }

// Gan gia tri cho ma nguoi muon
void Borrow::set_person_id(string person_id) {
  strcpy(person_id_, person_id.c_str());
}

// Tra ve ma nguoi muon
string Borrow::get_person_id() { return person_id_; }

// Gan gia tri cho ten nguoi muon
void Borrow::set_person_name(string person_name) {
  strcpy(person_name_, person_name.c_str());
}

// Tra ve ten nguoi muon
string Borrow::get_person_name() { return person_name_; }

// Gan gia tri cho ma sach
void Borrow::set_book_id(string book_id) { strcpy(book_id_, book_id.c_str()); }

// Tra ve ma sach
string Borrow::get_book_id() { return book_id_; }

// Gan gia tri cho ten sach
void Borrow::set_book_title(string book_title) {
  strcpy(book_title_, book_title.c_str());
}

// Tra ve ten sach
string Borrow::get_book_title() { return book_title_; }

// Gan gia tri cho ngay muon
void Borrow::set_day_borrowed(string day_borrowed) {
  strcpy(day_borrowed_, day_borrowed.c_str());
}

// Tra ve ngay muon sach
string Borrow::get_day_borrowed() { return day_borrowed_; }

// Gan gia tri cho tinh trang sach khi muosn
void Borrow::set_status_borrowed_book(string status_borrowed_book) {
  strcpy(status_borrowed_book_, status_borrowed_book.c_str());
}

// Tra ve tinh trang sach khi muon
string Borrow::get_status_borrowed_book() { return status_borrowed_book_; }

// Gan gia tri cho ngay tra
void Borrow::set_day_returned(string day_returned) {
  strcpy(day_returned_, day_returned.c_str());
}

// Tra ve ngay tra sach
string Borrow::get_day_returned() { return day_returned_; }

// Gan gia tri cho tinh trang sach khi tra
void Borrow::set_status_returned_book(string status_returned_book) {
  strcpy(status_returned_book_, status_returned_book.c_str());
}

// Tra ve tinh trang sach khi tra
string Borrow::get_status_returned_book() { return status_returned_book_; }

// Gan gia tri cho trang thai phieu muon
void Borrow::set_borrow_status(string borrow_status) {
  strcpy(borrow_status_, borrow_status.c_str());
}

// Tra ve trang thai phieu muon
string Borrow::get_borrow_status() { return borrow_status_; }

//----------------------------------------------------------------------//

// Nhap thong tin phieu muon sach
void Borrow::input_an_info() {

  bool check = true; // Gia tri kiem tra nhap dung/sai

  // Dong thong bao khi nhap sai
  char str_error[] = "\n Nhap sai, vui long nhap lai!\n\n";

  cin.ignore();

  // Nhap ma phieu muon
  do {
    try {
      check = true;
      cout << " Ma phieu (6 so): ";
      cin.getline(borrow_id_, LENGTH_BORROW_ID);
      if (strlen(borrow_id_) != LENGTH_BORROW_ID - 1 || cin.fail())
        throw str_error;
      else {
        for (int i = 0; i < strlen(borrow_id_); i++) {
          if (!isdigit(borrow_id_[i]))
            throw str_error;
        }
      }

      //-------------Kiem tra ma phieu muon da ton tai chua------------------//
      // Yeu cau nhap lai neu ma phieu muon da ton tai
      ifstream in_file;
      Borrow borrow;
      in_file.open(BORROW_FILE, ios::app | ios::binary);
      if (!in_file)
        throw "\n  Loi mo file\n";

      // Doc thong tin sach cho den het file (khong doc duoc nua)
      while (in_file.read(reinterpret_cast<char *>(&borrow), sizeof(borrow))) {
        if (borrow.get_borrow_id() == borrow_id_) {
          in_file.close();
          throw "\n Ma phieu muon da ton tai!\n\n";
        }
      }
      in_file.close();
      //---------------------------------------------------------------------//
    } catch (const char *str) {
      cerr << str;
      check = false;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);

  // Nhap ma nguoi muon
  do {
    check = true;
    try {
      cout << " Ma nguoi muon (6 so): ";
      cin.getline(person_id_, LENGTH_PERSON_ID);
      if (strlen(person_id_) != LENGTH_PERSON_ID - 1 || cin.fail())
        throw str_error;
      else {
        for (int i = 0; i < strlen(person_id_); i++) {
          if (!isdigit(person_id_[i]))
            throw str_error;
        }
      }
    } catch (const char *str) {
      cerr << str;
      check = false;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);

  // Nhap Ten nguoi muon
  do {
    check = true;
    cout << " Ten nguoi muon: ";
    cin.getline(person_name_, LENGTH_PERSON_NAME);
    try {
      if (cin.fail() || !Book::check_string(this->get_person_name()))
        throw str_error;
    } catch (const char *str) {
      cerr << str;
      check = false;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);

  // Nhap Ma sach
  do {
    check = true;
    try {
      check = true;
      cout << " Ma sach (6 so): ";
      cin.getline(book_id_, LENGTH_BOOK_ID);
      if (strlen(book_id_) != LENGTH_BOOK_ID - 1 || cin.fail())
        throw str_error;
      else {
        for (int i = 0; i < strlen(book_id_); i++) {
          if (!isdigit(book_id_[i]))
            throw str_error;
        }
      }

      //-------------Kiem tra Ma sach co ton tai khong------------------//
      // Yeu cau nhap lai neu ma sach khong ton tai
      ifstream in_file;
      Book book;
      in_file.open(BOOK_FILE, ios::app | ios::binary);
      if (!in_file)
        throw "\n  Loi mo file\n";

      check = false;
      // Doc thong tin sach cho den het file (khong doc duoc nua)
      while (in_file.read(reinterpret_cast<char *>(&book), sizeof(book))) {
        if (book.get_book_id() == book_id_) {
          check = true;
          in_file.close();
          break;
        }
      }

      if (check == false)
        throw "\n Ma sach khong ton tai!\n\n";

      in_file.close();
      //---------------------------------------------------------------//
    } catch (const char *str) {
      cerr << str;
      check = false;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);

  // Nhap ngay muon sach dang dd/mm/yyyy
  do {
    check = true;
    cout << " Ngay muon (dd/mm/yyyy): ";
    cin.getline(day_borrowed_, LENGTH_DAY_BORROWED);
    try {
      if (strlen(day_borrowed_) != LENGTH_DAY_BORROWED - 1 || cin.fail())
        throw str_error;
    } catch (const char *str) {
      cerr << str;
      check = false;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);

  int choice;
  cout << "\n Chon tinh trang sach:\n";
  cout << " 1: Tot\n";
  cout << " 2: Binh thuong\n";
  cout << " 3: Cu\n";

  // Nhap tinh trang sach khi muon
  do {
    check = true;
    cout << " Tinh trang sach: ";
    cin >> choice;
    try {
      if (choice < 0 || choice > 3 || cin.fail())
        throw str_error;
    } catch (const char *str) {
      cerr << str;
      check = false;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);

  // Gan tinh trang sach theo so da nhap
  // 1 = Tot
  // 2 = Binh thuong
  // 3 = Cu
  if (choice == 1)
    strcpy(status_borrowed_book_, "Tot");
  else if (choice == 2)
    strcpy(status_borrowed_book_, "Binh thuong");
  else if (choice == 3)
    strcpy(status_borrowed_book_, "Cu");

  // Gan tieu de sach vao phieu muon
  ifstream in_file;
  try {
    in_file.open(BOOK_FILE, ios::app | ios::binary);
    if (!in_file)
      throw "\n  Loi mo file!\n";
    Book book;
    while (in_file.read(reinterpret_cast<char *>(&book), sizeof(book))) {
      if (book.get_book_id() == this->get_book_id()) {
        strcpy(book_title_, book.get_book_title().c_str());
        break;
      }
    }
  } catch (const char *str_error) {
    cout << str_error << BOOK_FILE << endl;
    return;
  } catch (...) {
    cerr << "\n  Loi doc file!\n" << BOOK_FILE;
  }
  in_file.close();

  // Gan trang thai Dang muon cho phieu muon khi tao phieu muon
  strcpy(borrow_status_, "Dang muon");
}
// Nhap thong tin phieu tra sach
void Borrow::input_return() {

  bool check = true; // Gia tri kiem tra nhap dung/sai

  // Dong thong bao khi nhap sai
  char str_error[] = "\n Nhap sai, vui long nhap lai!\n\n";

  cin.ignore();

  // Nhap ma phieu muon
  do {
    check = true;
    try {
      cout << " Ma phieu (6 so): ";
      cin.getline(borrow_id_, LENGTH_BORROW_ID);
      if (strlen(borrow_id_) != LENGTH_BORROW_ID - 1 || cin.fail())
        throw str_error;
      else {
        for (int i = 0; i < strlen(borrow_id_); i++) {
          if (!isdigit(borrow_id_[i]))
            throw str_error;
        }
      }

      //-------------Kiem tra ma phieu muon da ton tai chua------------------//
      ifstream in_file;
      Borrow borrow;
      in_file.open(BORROW_FILE, ios::app | ios::binary);
      if (!in_file)
        throw "\n  Loi mo file!\n";

      check = false;
      // Doc thong tin sach cho den het file (khong doc duoc nua)
      while (in_file.read(reinterpret_cast<char *>(&borrow), sizeof(borrow))) {
        if (borrow.get_borrow_id() == this->borrow_id_) {
          check = true;
          break;
        }
      }

      if (check == false)
        throw "\n Ma phieu muon khong ton tai!\n\n";

      in_file.close();
      //--------------------------------------------------------------------//
    } catch (const char *str) {
      cerr << str;
      check = false;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);

  // Nhap ngay tra sach
  do {
    check = true;
    cout << " Nhap ngay tra: ";
    cin.getline(day_returned_, LENGTH_DAY_RETURN);
    try {
      if (strlen(day_returned_) != LENGTH_DAY_RETURN - 1 || cin.fail())
        throw str_error;
      //---------------Kiem tra ngay tra nhap truoc ngay muon-----------------//
      // Yeu cau nhap lai neu nhap ngay tra truoc ngay muon
      ifstream in_file;
      in_file.open(BORROW_FILE, ios::app | ios::binary);
      if (!in_file)
        throw "\n Loi mo file!\n";
      Borrow borrow;
      while (in_file.read(reinterpret_cast<char *>(&borrow), sizeof(borrow))) {
        if (borrow.get_borrow_id() == this->get_borrow_id()) {
          if (this->get_day_returned() < borrow.get_day_borrowed())
            throw "\n Ngay tra khong the truoc ngay muon!\n\n";
          break;
        }
      }
      //--------------------------------------------------------------------//
    } catch (const char *str) {
      cerr << str;
      check = false;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);

  int choice;
  cout << "\n Chon tinh trang sach:\n";
  cout << " 1: Tot\n";
  cout << " 2: Binh thuong\n";
  cout << " 3: Cu\n";

  // Nhap tinh trang sach khi tra
  do {
    check = true;
    cout << " Tinh trang sach: ";
    cin >> choice;
    try {
      if (choice < 0 || choice > 3 || cin.fail())
        throw str_error;
    } catch (const char *str) {
      cerr << str;
      check = false;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);

  // Gan tinh trang sach theo so da nhap
  // 1 = Tot
  // 2 = Binh thuong
  // 3 = Cu
  if (choice == 1)
    strcpy(status_returned_book_, "Tot");
  else if (choice == 2)
    strcpy(status_returned_book_, "Binh thuong");
  else if (choice == 3)
    strcpy(status_returned_book_, "Cu");

  // Gan trang thai Da tra cho phieu muon khi tra sach
  strcpy(borrow_status_, "Da tra");
}

// Xuat thong tin phieu muon
void Borrow::display_borrowing(int i) {
  cout << " ";
  cout << " " << setw(5) << left << i;
  cout << " " << setw(10) << left << borrow_id_;
  cout << " " << setw(15) << left << person_id_;
  cout << " " << setw(24) << left << person_name_;
  cout << " " << setw(9) << left << book_id_;
  cout << " " << setw(30) << left << book_title_;
  cout << " " << setw(11) << left << day_borrowed_;
  cout << " " << setw(14) << left << status_borrowed_book_;
  cout << " " << setw(13) << left << borrow_status_;
  cout << endl;
}

// Xuat thongn tin phieu muon da tra
void Borrow::display_returned(int i) {
  cout << " ";
  cout << " " << setw(5) << left << i;
  cout << " " << setw(10) << left << borrow_id_;
  cout << " " << setw(15) << left << person_id_;
  cout << " " << setw(24) << left << person_name_;
  cout << " " << setw(9) << left << book_id_;
  cout << " " << setw(30) << left << book_title_;
  cout << " " << setw(11) << left << day_borrowed_;
  cout << " " << setw(11) << left << day_returned_;
  cout << " " << setw(14) << left << status_borrowed_book_;
  cout << " " << setw(14) << left << status_returned_book_;
  cout << " " << setw(13) << left << borrow_status_;
  cout << endl;
}

// Xuat danh sach phieu muon theo trang thai
void Borrow::display_borrow_list(vector<Borrow> borrows, string status) {
  vector<Borrow>::iterator it;
  int i = 0;
  for (it = borrows.begin(); it < borrows.end(); it++)
    if (it->get_borrow_status() == status) {
      i++;
      if (status == "Dang muon")
        // Hien thi thong tin phieu muon neu status la Dang muon
        it->display_borrowing(i);
      else if (status == "Da tra")
        // Hien thi thong tin phieu muon neu status la Da tra
        it->display_returned(i);
    }
}

// Ghi thong tin phieu muon vao file BORROW_FILE (Danh sach phieu muon)
void Borrow::write_borrow_info(vector<Borrow> write_borrows, string file_name) {
  ofstream out_file;
  try {
    out_file.open(file_name, ios::app | ios::binary);
    if (!out_file)
      throw "\n  Loi mo file ";
    // Luu thong tin da nhap vao file
    out_file.write(reinterpret_cast<char *>(&write_borrows.back()),
                   sizeof(write_borrows.back()));
  } catch (const char *str_error) {
    cout << str_error << file_name << endl;
    return;
  } catch (...) {
    cerr << "\n  Loi ghi file " << file_name;
  }
  out_file.close();
}

// Doc thong tin tu file BORROW_FILE (Danh sach phieu muon)
void Borrow::read_borrow_info(vector<Borrow> &borrows, string file_name) {
  ifstream in_file;
  try {
    in_file.open(file_name, ios::binary);
    if (!in_file)
      throw "\n  Loi mo file ";
    Borrow borrow;
    while (in_file.read(reinterpret_cast<char *>(&borrow), sizeof(borrow))) {
      // Luu thong tin phieu muon vua doc duoc tu file vao container borrows
      borrows.push_back(borrow);
    }
  } catch (const std::exception &e) {
    std::cerr << " " << e.what() << '\n';
  }
}

// Hien thi tieu de danh sach phieu dang muon
void Borrow::title_borrowing_list() {
  cout << " ";
  cout << setw(6) << left << "| STT ";
  cout << setw(11) << left << "| Ma phieu ";
  cout << setw(16) << left << "| Ma nguoi muon ";
  cout << setw(25) << left << "| Ten nguoi muon ";
  cout << setw(10) << left << "| Ma sach ";
  cout << setw(31) << left << "| Ten sach ";
  cout << setw(12) << left << "| Ngay muon ";
  cout << setw(15) << left << "| TT sach muon ";
  cout << setw(14) << left << "| Trang thai |";
  cout << endl;
}

// Hien thi tieu de danh sach phieu dang muon
void Borrow::title_returned_list() {
  cout << " ";
  cout << setw(6) << left << "| STT ";
  cout << setw(11) << left << "| Ma phieu ";
  cout << setw(16) << left << "| Ma nguoi muon ";
  cout << setw(25) << left << "| Ten nguoi muon ";
  cout << setw(10) << left << "| Ma sach ";
  cout << setw(31) << left << "| Ten sach ";
  cout << setw(12) << left << "| Ngay muon ";
  cout << setw(12) << left << "| Ngay tra ";
  cout << setw(15) << left << "| TT sach muon ";
  cout << setw(15) << left << "| TT sach tra ";
  cout << setw(14) << left << "| Trang thai |";
  cout << endl;
}