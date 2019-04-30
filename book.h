#ifndef BOOK_H_
#define BOOK_H_

// Using strcpy replace for strcpy_s on MSVS compiler
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

#include <iostream>
#include <exception>
#include <fstream>
#include <iomanip>  // setfill, setw
#include <limits>   // numeric_litmits
#include <string.h> // strcpy
#include <string>
#include <list>
#include <algorithm> // sort, reverse

using namespace std;

#define BOOK_FILE "./Data/Books.bin"           // File luu danh sach sach
#define TEMP_BOOK_FILE "./Data/Books_temp.bin" // File luu tam

#define LENGTH_BOOK_ID 7     // Ma sach co 6 chu so
#define LENGTH_BOOK_TITLE 51 // Tieu de sach toi da 50 ky tu
#define LENGTH_PUBLISHER 31  // Ten nha xuat ban toi da 30 ky tu
#define LENGTH_AUTHOR 31     // Ten tac gia toi da 30 ky tu
#define LENGTH_TYPE 31       // The loai sach to da 30 ky tu

class Book
{
private:
  char book_id_[LENGTH_BOOK_ID];       // Ma sach
  char book_title_[LENGTH_BOOK_TITLE]; // Tieu de sach
  unsigned short year_;                // Nam xuat ban
  char publisher_[LENGTH_PUBLISHER];   // Nha xuat ban
  char author_[LENGTH_AUTHOR];         // Tac gia
  char type_[LENGTH_TYPE];             // The loai
  int amount_;                         // So luong

public:
  // Ham khoi tao khong tham so
  Book();

  // Ham khoi tao co tham so
  Book(char *, char *, unsigned short, char *, char *, char *, int);

  // Ham huy
  ~Book();

  //------------------------------------------------------------------//

  // Gan gia tri cho ma sach
  void set_book_id(string);

  // Tra ve ma sach
  string get_book_id();

  // Gan gia tri cho tieu de sach
  void set_book_title(string);

  // Tra ve tieu de sach
  string get_book_title();

  // Gan gia tri cho nam xuat ban
  void set_year(unsigned short);

  // Tra ve nam xuat ban cua sach
  unsigned short get_year();

  // Gan gia tri cho nha xua ban
  void set_publisher(string);

  // Tra ve ten nha xuat ban
  string get_publisher();

  // Gan gia tri cho ten tac gia
  void set_author(string);

  // Tra ve ten tac gia
  string get_author();

  // Tra ve ten tac gia de sap xep danh sach theo ten
  string get_person_name();

  // Gan gia tri cho the loai sach
  void set_type(string);

  // Tra ve the loai sach
  string get_type();

  // Gan so luong sach
  void set_amount(int);

  // Tra ve so luong sach
  int get_amount();

  //------------------------------------------------------------------//

  // Nhap thong tin sach
  virtual void input_an_info();

  // Hien thi danh sach sach
  void display_book_list(list<Book>);

  // Xuat thong tin mot sach
  void display_book_info(int);

  // Hien thi tieu de cot danh sach sach
  void title_books_list();

  // Kiem tra chuoi co chua so khong
  static bool check_string(string);
};

#endif // BOOK_H_