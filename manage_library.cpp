#include "manage_library.h"

// Dung de tao con tro ham tro den ham cua class Book
// co kieu tra ve unsigned short
typedef unsigned short (Book::*Book_memfnc_ushort)();

// Dung de tao con tro ham tro den ham cua class Book
// co kieu tra ve string
typedef string (Book::*Book_memfnc_str)();

// Dung de tao con tro ham tro den ham cua class Borrow
// co kieu tra ve string
typedef string (Borrow::*Borrow_memfnc_str)();

// Hien thi menu chinh
void menu_main_option()
{
  cout << "\n CHUONG TRINH QUAN LY THU VIEN\n";
  cout << "\n ============================================";
  cout << "\n\n Moi ban chon";
  cout << "\n\n 1. Nhap thong tin sach.";
  cout << "\n\n 2. Danh sach thong tin sach.";
  cout << "\n\n 3. Muon sach.";
  cout << "\n\n 4. Tra sach.";
  cout << "\n\n 5. Danh sach phieu muon sach.";
  cout << "\n\n 6. Tim kiem.";
  cout << "\n\n 0. Thoat.";
  cout << "\n\n ============================================\n";
}

// Menu lua chon kieu sap xep danh sach sach
void menu_list_book_option()
{
  cout << "\n DANH SACH THONG TIN SACH\n";
  cout << "\n\n 1. Sap xep theo tieu de sach";
  cout << "\n\n 2. Sap xep theo nam xuat ban";
  cout << "\n\n 3. Sap xep theo nha xuat ban";
  cout << "\n\n 4. Sap xep theo tac gia";
  cout << "\n\n 5. Sap xep theo sach moi nhat";
  cout << "\n\n 0. Tro ve\n";
}

// Menu lua chon hien thi danh sach phieu muon
void menu_list_borrow_option()
{
  cout << "\n DANH SACH PHIEU MUON\n";
  cout << "\n\n 1. Danh sach phieu dang muon";
  cout << "\n\n 2. Danh sach phieu muon da tra";
  cout << "\n\n 3. Tat ca danh sach (Theo trang thai muon)";
  cout << "\n\n 0. Tro ve\n";
}

// Menu lua chon tim kiem sach/phieu muon
void menu_search_option()
{
  cout << "\n TIM KIEM\n";
  cout << "\n\n 1. Sach";
  cout << "\n\n 2. Phieu muon";
  cout << "\n\n 0. Tro ve\n";
}

// Menu lua chon tim kiem sach
void menu_search_book()
{
  cout << "\n TIM KIEM SACH\n";
  cout << "\n\n 1. Theo ma sach";
  cout << "\n\n 2. Theo tieu de sach";
  cout << "\n\n 3. Theo nam xuat ban";
  cout << "\n\n 4. Theo nha xuat ban";
  cout << "\n\n 5. Theo tac gia";
  cout << "\n\n 6. Theo The loai";
  cout << "\n\n 0. Tro ve menu chinh\n";
}

// Menu lua chon tim kiem phieu muon
void menu_search_borrow()
{
  cout << "\n TIM KIEM PHIEU MUON\n";
  cout << "\n\n 1. Theo ma phieu muon";
  cout << "\n\n 2. Theo ma nguoi muon";
  cout << "\n\n 3. Theo ten nguoi muon";
  cout << "\n\n 4. Theo ngay muon";
  cout << "\n\n 5. Theo ngay tra";
  cout << "\n\n 6. Theo tinh trang sach";
  cout << "\n\n 0. Tro ve menu chinh\n";
}

// Menu lua chon sap xep phieu dang muon
void menu_sort_borrowing()
{
  cout << "\n 1. Sap xep theo ngay muon";
  cout << "\n\n 2. Sap xep theo ten nguoi muon";
  cout << "\n\n 0. Tro ve menu chinh\n";
}

// Menu lua chon sap xep phieu muon da tra
void menu_sort_returned()
{
  cout << "\n 1. Sap xep theo ngay muon";
  cout << "\n\n 2. Sap xep theo ten nguoi muon";
  cout << "\n\n 3. Sap xep theo ngay tra";
  cout << "\n\n 0. Tro ve menu chinh\n";
}

// Xu ly lua chon menu chinh
void main_menu()
{
  int menu_choice;
  do
  {
    clear_screen();     // Xoa man hinh
    menu_main_option(); // Hien thi menu chinh
    cout << "\n Nhap lua chon cua ban: ";
    cin >> menu_choice;

    while (menu_choice < 0 || menu_choice > 6 || cin.fail())
    {
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      clear_screen();     // Xoa man hinh
      menu_main_option(); // Hien thi menu chinh
      cout << "\n Nhap sai! vui long nhap lai\n";
      cout << "\n Nhap lua chon cua ban: ";
      cin >> menu_choice;
    }

    clear_screen(); // Xoa man hinh

    list<Book> books_write;     // Chua danh sach sach da nhap de luu vao file
    list<Borrow> borrows_write; // Chua danh sach phieu muon de luu vao file

    switch (menu_choice)
    {
    case 1: // Nhap thong tin sach
    {
      cout << "\n NHAP THONG TIN SACH\n\n";
      // Nhap thong tin sach
      input_info<list<Book>, Book>(books_write, BOOK_FILE);
      cout << "\n Luu thong tin thanh cong!\n";
      cin.get();
    }
    break;

    case 2: // Danh sach thong tin sach.
    {
      int choice;
      // Menu lua chon kieu sap xep danh sach sach
      menu_list_book_option();
      cout << "\n Nhap lua chon cua ban: ";
      cin >> choice;

      while (choice < 0 || choice > 5 || cin.fail())
      {
        if (cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        clear_screen(); // Xoa man hinh
        menu_list_book_option();
        cout << "\n Nhap sai! Vui long nhap lai\n";
        cout << "\n Nhap lua chon cua ban: ";
        cin >> choice;
      }

      // Tro ve menu chinh khi chon 0
      if (choice == 0)
        break;

      clear_screen(); // Xoa man hinh
      cout << "\n DANH SACH THONG TIN SACH\n\n";

      list<Book> books_read;
      // Doc danh sach sach tu file luu vao container books_read
      read_list_from_file<list<Book>, Book>(books_read, BOOK_FILE);

      switch (choice)
      {
      case 1:
      {
        // Con tro ham get_title tro den ham Book::get_book_title()
        Book_memfnc_str get_title = &Book::get_book_title;

        // Sap xep danh sach sach trong books_read theo ten sach
        bubble_sort<list<Book>, list<Book>::iterator, Book, Book_memfnc_str>(books_read, get_title);
      }
      break;

      case 2:
      {
        // Con tro ham get_year tro den ham Book::get_year()
        Book_memfnc_ushort get_year = &Book::get_year;

        // Sap xep danh sach sach trong books_read theo nam xuat ban
        selection_sort<list<Book>, list<Book>::iterator, Book, Book_memfnc_ushort>(books_read, get_year);
      }
      break;

      case 3:
      {
        // Con tro ham get_publisher tro den ham Book::get_publisher()
        Book_memfnc_str get_publisher = &Book::get_publisher;

        // Sap xep danh sach sach trong books_read theo nha xuat ban
        insertion_sort<list<Book>, list<Book>::iterator, Book, Book_memfnc_str>(books_read, get_publisher);
      }
      break;

      case 4:
      {
        // Con tro ham get_author tro den ham Book::get_author()
        Book_memfnc_str get_author = &Book::get_author;

        // Sap xep danh sach sach trong books_read theo ten tac gia
        merge_sort<list<Book>, list<Book>::iterator, Book_memfnc_str>(books_read, books_read.begin(), --books_read.end(), get_author);
      }
      break;

      case 5:
        // Dao nguoc danh sach sach trong books_read de hien thi sach moi nhat
        // len dau danh sach
        reverse(books_read.begin(), books_read.end());
        break;

      default:
        break;
      }

      // Xuat danh sach da sap xep trong books_read ra man hinh
      display_list<list<Book>, list<Book>::iterator, Book>(books_read);

      cout << " " << setfill('=') << setw(127) << "=" << setfill(' ') << endl;
      cin.get();
    }
    break;

    case 3: // Muon sach
    {
      cout << "\n NHAP THONG TIN PHIEU MUON SACH\n\n";

      // Nhap thong tin phieu muon roi luu vao container borrows_write
      input_info<list<Borrow>, Borrow>(borrows_write, BORROW_FILE);

      list<Book> books_read;
      // Doc danh sach sach tu file luu vao container books_read
      read_list_from_file<list<Book>, Book>(books_read, BOOK_FILE);

      Borrow borrow;
      borrow = borrows_write.back(); // Luu phieu muon vua nhap

      // Giam so luong sach da muon di 1
      change_amount(books_read, borrow.get_book_id(), -1);

      cout << "\n Nhap thong tin thanh cong!\n";
      cin.get();
    }
    break;

    case 4: // Tra sach
    {
      cout << "\n NHAP THONG TIN TRA SACH\n\n";

      Borrow borrow;
      borrow.input_return(); // Nhap thong tin tra sach

      list<Borrow> borrows_read;
      // Doc danh sach phieu muon tu file luu vao container borrows_read
      read_list_from_file<list<Borrow>, Borrow>(borrows_read, BORROW_FILE);

      // Thay doi thong tin phieu muon khi tra sach
      change_borrow(borrows_read, borrow);

      cout << "\n Nhap thong tin thanh cong!\n";

      list<Book> books_read;
      // Doc danh sach sach tu file luu vao container books_read
      read_list_from_file<list<Book>, Book>(books_read, BOOK_FILE);

      // Tang so luong cua sach da tra len 1
      change_amount(books_read, borrow.get_book_id(), 1);
      cin.get();
    }
    break;

    case 5: // Danh sach phieu muon sach
    {
      // Thuc hien lua chon menu danh sach phieu muon
      display_borrowed_option();
    }
    break;

    case 6: // Tim kiem
    {
      // Thuc hien chuc nang tim kiem
      search_option();
    }
    break;

    case 0: // Thoat khi nhap 0
      return;
      break;

    default:
      break;
    }
    cin.ignore();

  } while (menu_choice != 0); // Thoat khi nhap 0
}

// Thuc hien chuc nang tim kiem
void search_option()
{
  int choice;
  menu_search_option(); // Menu lua chon tim kiem sach/phieu muon
  cout << "\n Nhap lua chon cua ban: ";
  cin >> choice;
  while (choice < 0 || choice > 2 || cin.fail())
  {
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    clear_screen(); // Xoa man hinh
    // Menu lua chon hien thi danh sach phieu muon
    menu_search_option(); // Menu lua chon tim kiem sach/phieu muon
    cout << "\n Nhap sai! Vui long nhap lai\n";
    cout << "\n Nhap lua chon cua ban: ";
    cin >> choice;
  }
  clear_screen(); // Xoa man hinh

  // Tro ve menu chinh khi chon 0
  if (choice == 0)
    return;
  if (choice == 1)
  {
    list<Book> result;   // Luu ket qua tim kiem
    search_book(result); // Thuc hien tim sach

    // Thuc hien xuat danh sach sach neu tim thay
    if (result.size() != 0)
    {
      display_list<list<Book>, list<Book>::iterator, Book>(result);
      cout << " " << setfill('=') << setw(127) << "=" << setfill(' ') << endl;
    }
  }
  if (choice == 2)
  {
    list<Borrow> result;   // Luu ket qua tim kiem
    search_borrow(result); // Thuc hien tim phieu muon

    // Thuc hien xuat danh sach phieu muon neu tim thay
    if (result.size() != 0)
    {
      display_list<list<Borrow>, list<Borrow>::iterator, Borrow>(result);
      cout << " " << setfill('=') << setw(167) << "=" << setfill(' ') << endl;
    }
  }
}

// Tim kiem sach
void search_book(list<Book> &result)
{
  int choice;
  menu_search_book(); // Menu lua chon tim kiem sach
  cout << "\n Nhap lua chon cua ban: ";
  cin >> choice;
  while (choice < 0 || choice > 6 || cin.fail())
  {
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    clear_screen();     // Xoa man hinh
    menu_search_book(); // Menu lua chon tim kiem sach
    cout << "\n Nhap sai! Vui long nhap lai";
    cout << "\n Nhap lua chon cua ban: ";
    cin >> choice;
  }

  // Tro ve menu chinh khi chon 0
  if (choice == 0)
    return;
  else
    clear_screen(); // Xoa man hinh

  cin.ignore(); // Bo qua ky tu enter

  list<Book> books_read;
  // Doc danh sach sach tu file luu vao container books_read
  read_list_from_file<list<Book>, Book>(books_read, BOOK_FILE);

  // Dong thong bao khi nhap sai
  char str_error[] = "\n Nhap sai! vui long nhap lai\n";

  cout << "\n TIM KIEM SACH\n\n";

  switch (choice)
  {
  case 1: // Tim kiem sach theo ma sach
  {
    string key;
    bool check;

    // Nhap Ma sach
    do
    {
      check = true;
      try
      {
        cout << "\n Nhap Ma sach (6 so): ";
        getline(cin, key);
        if (key.length() != LENGTH_BOOK_ID - 1 || cin.fail())
          throw str_error;
        else
        {
          for (unsigned int i = 0; i < key.length(); i++)
          {
            if (!isdigit(key[i]))
              throw str_error;
          }
        }
      }
      catch (const char *str)
      {
        cerr << str;
        check = false;
        if (cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
    } while (!check);

    clear_screen(); // Xoa man hinh

    cout << "\n TIM KIEM SACH\n\n";
    cout << "\n Ma sach: " << key << endl;

    // Con tro ham get_book_id tro den ham Book::get_book_id()
    Book_memfnc_str get_book_id = &Book::get_book_id;

    // Sap xep danh sach sach trong books_read theo ma sach de thuc hien tim kiem
    // nhi phan
    merge_sort<list<Book>, list<Book>::iterator, Book_memfnc_str>(books_read, books_read.begin(), --books_read.end(), get_book_id);

    // Tim kiem sach voi ma sach key
    binary_search<list<Book>, list<Book>::iterator, string, Book_memfnc_str>(books_read, key, result, get_book_id);
  }
  break;

  case 2: // Tim kiem sach theo tieu de sach
  {
    string key;
    bool check;

    // Nhap Ten sach
    do
    {
      check = true;
      cout << "\n Nhap Ten sach: ";
      getline(cin, key);
      try
      {
        if (cin.fail())
          throw str_error;
      }
      catch (const char *str)
      {
        cerr << str;
        check = false;
        if (cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
    } while (!check);

    clear_screen(); // Xoa man hinh

    cout << "\n TIM KIEM SACH\n\n";
    cout << "\n Ten sach: " << key << endl;

    // Con tro ham get_book_title tro den ham Book::get_book_title()
    Book_memfnc_str get_book_title = &Book::get_book_title;

    // Tim kiem sach theo ten sach key
    linear_search<list<Book>, list<Book>::iterator, string, Book_memfnc_str>(books_read, key, result, get_book_title);
  }
  break;

  case 3: // Tim kiem sach theo nam xuat ban
  {
    unsigned short key;
    bool check;

    // Nhap nam xuat ban
    do
    {
      check = true;
      cout << "\n Nhap Nam xuat ban (NXB > 1900): ";
      cin >> key;
      try
      {
        if (key <= 1900 || cin.fail())
          throw str_error;
      }
      catch (const char *str)
      {
        cerr << str;
        check = false;
        if (cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
    } while (!check);

    cin.ignore();   // Bo qua ky tu enter
    clear_screen(); // Xoa ma hinh

    cout << "\n TIM KIEM SACH\n\n";
    cout << "\n Nam xuat ban: " << key << endl;

    // Con tro ham get_year tro den ham Book::get_year()
    Book_memfnc_ushort get_year = &Book::get_year;

    // Tim kiem sach voi nam xuat ban key
    linear_search<list<Book>, list<Book>::iterator, unsigned short, Book_memfnc_ushort>(books_read, key, result, get_year);
  }
  break;

  case 4: // Tim kiem sach theo nha xuat ban
  {
    string key;
    bool check;

    // Nhap nha xuat ban
    do
    {
      check = true;
      cout << "\n Nhap Nha xuat ban: ";
      getline(cin, key);
      try
      {
        if (cin.fail())
          throw str_error;
      }
      catch (const char *str)
      {
        cerr << str;
        check = false;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    } while (!check);

    clear_screen(); // Xoa man hinh

    cout << "\n TIM KIEM SACH\n\n";
    cout << "\n Nha xuat ban: " << key << endl;

    // Con tro ham get_publisher tro den ham Book::get_publisher()
    Book_memfnc_str get_publisher = &Book::get_publisher;

    // Tim kiem sach voi nha xuat ban key
    linear_search<list<Book>, list<Book>::iterator, string, Book_memfnc_str>(books_read, key, result, get_publisher);
  }
  break;

  case 5: // Tim kiem sach theo ten tac gia
  {
    string key;
    bool check;

    // Nhap ten tac gia
    do
    {
      check = true;
      cout << "\n Nhap Ten tac gia: ";
      getline(cin, key);
      try
      {
        if (cin.fail() || !Book::check_string(key))
          throw str_error;
      }
      catch (const char *str)
      {
        cerr << str;
        check = false;
        if (cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
    } while (!check);

    clear_screen(); // Xoa man hinh

    cout << "\n TIM KIEM SACH\n\n";
    cout << "\n Ten tac gia: " << key << endl;

    // Con tro ham get_author tro den ham Book::get_publisher()
    Book_memfnc_str get_author = &Book::get_author;

    // Tim kiem sach voi nha xuat ban
    linear_search<list<Book>, list<Book>::iterator, string, Book_memfnc_str>(books_read, key, result, get_author);
  }
  break;

  case 6: // Tim kiem sach theo the loai
  {
    string key;
    bool check;

    // Nhap The loai sach
    do
    {
      check = true;
      cout << "\n Nhap The loai: ";
      getline(cin, key);
      try
      {
        if (cin.fail())
          throw str_error;
      }
      catch (const char *str)
      {
        cerr << str;
        check = false;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    } while (!check);

    clear_screen(); // Xoa man hinh

    cout << "\n TIM KIEM SACH\n\n";
    cout << "\n The loai sach: " << key << endl;

    // Con tro ham tro den ham get_publisher()
    Book_memfnc_str get_type = &Book::get_type;

    // Tim kiem sach voi nha xuat ban
    linear_search<list<Book>, list<Book>::iterator, string, Book_memfnc_str>(books_read, key, result, get_type);
  }
  break;

  default:
    break;
  }
}

// Tim kiem phieu muon
void search_borrow(list<Borrow> &result)
{
  int choice;
  menu_search_borrow(); // Menu lua chon tim kiem phieu muon
  cout << "\n Nhap lua chon cua ban: ";
  cin >> choice;
  while (choice < 0 || choice > 6 || cin.fail())
  {
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    clear_screen();       // Xoa man hinh
    menu_search_borrow(); // Menu lua chon tim kiem phieu muon
    cout << "\n Nhap sai! Vui long nhap lai\n";
    cout << "\n Nhap lua chon cua ban: ";
    cin >> choice;
  }

  // Tro ve menu chinh khi chon 0
  if (choice == 0)
    return;
  else
    clear_screen(); // Xoa man hinh

  cin.ignore(); // Bo qua ky tu enter

  list<Borrow> borrows_read;
  // Doc danh sach phieu muon tu file luu vao container borrows_read
  read_list_from_file<list<Borrow>, Borrow>(borrows_read, BORROW_FILE);

  // Dong thong bao khi nhap sai
  char str_error[] = "\n Nhap sai! vui long nhap lai\n";

  cout << "\n TIM KIEM PHIEU MUON\n\n";

  switch (choice)
  {
  case 1: // Tim kiem phieu muon theo ma phieu
  {
    string key;
    bool check;

    // Nhap Ma phieu muon
    do
    {
      check = true;
      try
      {
        cout << "\n Nhap Ma phieu muon (6 so): ";
        getline(cin, key);
        if (key.length() != LENGTH_BORROW_ID - 1 || cin.fail())
          throw str_error;
        else
        {
          for (unsigned int i = 0; i < key.length(); i++)
          {
            if (!isdigit(key[i]))
              throw str_error;
          }
        }
      }
      catch (const char *str)
      {
        cerr << str;
        check = false;
        if (cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
    } while (!check);

    clear_screen(); // Xoa man hinh

    cout << "\n TIM KIEM PHIEU MUON\n\n";

    cout << "\n Ma phieu muon: " << key << endl;

    // Con tro ham  get_borrow_id tro den ham Borrow::get_borrow_id()
    Borrow_memfnc_str get_borrow_id = &Borrow::get_borrow_id;

    // Sap xep danh sach phieu muon trong borrows_read theo ma phieu muon de thuc
    // hien tim kiem nhi phan
    merge_sort<list<Borrow>, list<Borrow>::iterator, Borrow_memfnc_str>(borrows_read, borrows_read.begin(), --borrows_read.end(), get_borrow_id);

    // Thuc hien tim kiem phieu muon theo ma phieu muon key
    binary_search<list<Borrow>, list<Borrow>::iterator, string, Borrow_memfnc_str>(borrows_read, key, result, get_borrow_id);
  }
  break;

  case 2: // Tim kiem phieu muon theo ma nguoi muon
  {
    string key;
    bool check;

    // Nhap Ma nguoi muon
    do
    {
      check = true;
      try
      {
        cout << "\n Nhap Ma nguoi muon (6 so): ";
        getline(cin, key);
        if (key.length() != LENGTH_PERSON_ID - 1 || cin.fail())
          throw str_error;
        else
        {
          for (unsigned int i = 0; i < key.length(); i++)
          {
            if (!isdigit(key[i]))
              throw str_error;
          }
        }
      }
      catch (const char *str)
      {
        cerr << str;
        check = false;
        if (cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
    } while (!check);

    clear_screen(); // Xoa man hinh

    cout << "\n TIM KIEM PHIEU MUON\n\n";

    cout << "\n Ma nguoi muon: " << key << endl;

    // Con tro ham get_person_id tro den ham Borrow::get_person_id()
    Borrow_memfnc_str get_person_id = &Borrow::get_person_id;

    // Thuc hien tim kiem phieu muon theo ma nguoi muon key
    linear_search<list<Borrow>, list<Borrow>::iterator, string, Borrow_memfnc_str>(borrows_read, key, result, get_person_id);
  }
  break;

  case 3: // Tim kiem phieu muon theo ten nguoi muon
  {
    string key;
    bool check;

    // Nhap Ten nguoi muon
    do
    {
      check = true;
      cout << "\n Nhap Ten nguoi muon: ";
      getline(cin, key);
      try
      {
        if (cin.fail() || !Book::check_string(key))
          throw str_error;
      }
      catch (const char *str)
      {
        cerr << str;
        check = false;
        if (cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
    } while (!check);

    clear_screen(); // Xoa man hinh

    cout << "\n TIM KIEM PHIEU MUON\n\n";

    cout << "\n Ten nguoi muon: " << key << endl;

    // Con tro ham get_person tro den Borrow::ham get_person_name()
    Borrow_memfnc_str get_person_name = &Borrow::get_person_name;

    // Thuc hien tim kiem phieu muon theo ten nguoi muon
    linear_search<list<Borrow>, list<Borrow>::iterator, string, Borrow_memfnc_str>(borrows_read, key, result, get_person_name);
  }
  break;

  case 4: // Tim kiem phieu muon theo ngay muon
  {
    string key;
    bool check;

    // Nhap ngay muon sach dang dd/mm/yyyy
    do
    {
      check = true;
      cout << "\n Nhap Ngay muon (dd/mm/yyyy): ";
      getline(cin, key);
      try
      {
        if (key.length() != LENGTH_DAY_BORROWED - 1 || cin.fail())
          throw str_error;
      }
      catch (const char *str)
      {
        cerr << str;
        check = false;
        if (cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
    } while (!check);

    clear_screen(); // Xoa man hinh

    cout << "\n TIM KIEM PHIEU MUON\n\n";

    cout << "\n Ngay muon (dd/mm/yyyy): " << key << endl;

    // Con tro ham get_day_borrowed tro den ham Borrow::get_day_borrowed()
    Borrow_memfnc_str get_day_borrowed = &Borrow::get_day_borrowed;

    // Thuc hien tim kiem phieu muon theo ngay muon
    linear_search<list<Borrow>, list<Borrow>::iterator, string, Borrow_memfnc_str>(borrows_read, key, result, get_day_borrowed);
  }
  break;

  case 5: // Tim kiem phieu muon theo ngay tra
  {
    string key;
    bool check;

    // Nhap ngay tra sach dang dd/mm/yyyy
    do
    {
      check = true;
      cout << "\n Nhap Ngay tra (dd/mm/yyyy): ";
      getline(cin, key);
      try
      {
        if (key.length() != LENGTH_DAY_RETURN - 1 || cin.fail())
          throw str_error;
      }
      catch (const char *str)
      {
        cerr << str;
        check = false;
        if (cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
    } while (!check);

    clear_screen(); // Xoa man hinh

    cout << "\n TIM KIEM PHIEU MUON\n\n";

    cout << "\n Ngay tra (dd/mm/yyyy): " << key << endl;

    // Con tro ham get_day_returned tro den ham Borrow::get_day_returned()
    Borrow_memfnc_str get_day_returned = &Borrow::get_day_returned;

    // Thuc hien tim kiem phieu muon theo ngay tra
    linear_search<list<Borrow>, list<Borrow>::iterator, string, Borrow_memfnc_str>(borrows_read, key, result, get_day_returned);
  }
  break;

  case 6: // Tim kiem phieu muon theo tinh trang sach
  {
    bool check;
    int key;
    cout << "\n Chon tinh trang sach:\n";
    cout << " 1: Tot\n";
    cout << " 2: Binh thuong\n";
    cout << " 3: Cu\n";

    // Nhap tinh trang sach de tim kiem
    do
    {
      check = true;
      cout << "\n Tinh trang sach: ";
      cin >> key;
      cin.ignore();
      try
      {
        if (key < 1 || key > 3 || cin.fail())
          throw str_error;
      }
      catch (const char *str)
      {
        cerr << str;
        check = false;
        if (cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
    } while (!check);

    clear_screen(); // Xoa man hinh
    string find;

    cout << "\n TIM KIEM PHIEU MUON\n\n";
    cout << "\n Tinh trang sach: ";
    if (key == 1)
    {
      cout << "Tot" << endl;
      find = "Tot";
    }
    if (key == 2)
    {
      cout << "Binh thuong" << endl;
      find = "Binh thuong";
    }
    if (key == 3)
    {
      cout << "Cu" << endl;
      find = "Cu";
    }

    // Con tro ham status_borrowed tro den ham Borrow::get_status_borrowed_book()
    Borrow_memfnc_str status_borrowed = &Borrow::get_status_borrowed_book;

    // Thuc hien tim phieu muon theo tinh trang sach khi muon
    linear_search<list<Borrow>, list<Borrow>::iterator, string, Borrow_memfnc_str>(borrows_read, find, result, status_borrowed);

    // Con tro ham status_returned tro den ham Borrow::get_status_returned_book()
    Borrow_memfnc_str status_returned = &Borrow::get_status_returned_book;

    // Thuc hien tim kiem phieu muon theo tinh trang sach tra
    linear_search<list<Borrow>, list<Borrow>::iterator, string, Borrow_memfnc_str>(borrows_read, find, result, status_returned);
  }
  break;

  default:
    break;
  }
}

// Nhap lua chon menu sap xep danh sach phieu muon
// Thuc hien sap xep theo lua chon
void sort_borrows(list<Borrow> &borrows, string title, int &choice, int status)
{
  cout << title;

  if (status == 1)
  {
    // Menu lua chon sap xep danh sach phieu dang muon
    menu_sort_borrowing();
    cout << "\n Nhap lua chon cua ban: ";
    cin >> choice;
    while (choice < 0 || choice > 2 || cin.fail())
    {
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      clear_screen(); // Xoa man hinh
      cout << title;
      // Menu lua chon sap xep danh sach phieu dang muon
      menu_sort_borrowing();
      cout << "\n Nhap sai! Vui long nhap lai\n";
      cout << "\n Nhap lua chon cua ban: ";
      cin >> choice;
    }
  }

  if (status == 2)
  {
    // Menu lua chon sap xep danh sach phieu muon da tra
    menu_sort_returned();
    cout << "\n Nhap lua chon cua ban: ";
    cin >> choice;
    while (choice < 0 || choice > 3 || cin.fail())
    {
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      clear_screen(); // Xoa man hinh
      cout << title;
      // Menu lua chon sap xep danh sach phieu muon da tra
      menu_sort_returned();
      cout << "\n Nhap sai! Vui long nhap lai\n";
      cout << "\n Nhap lua chon cua ban: ";
      cin >> choice;
    }
  }

  clear_screen(); // xoa man hinh

  switch (choice)
  {
  case 1: // Sap xep danh sach phieu muon theo ngay muon
  {
    // Con tro ham get_day_borrowed tro den ham Borrow::get_day_borrowed()
    Borrow_memfnc_str get_day_borrowed = &Borrow::get_day_borrowed;

    // Sap xep danh sach phieu muon theo ngay muon tang dan
    selection_sort<list<Borrow>, list<Borrow>::iterator, Borrow, Borrow_memfnc_str>(borrows, get_day_borrowed);
  }
  break;

  case 2: // Sap xep danh sach phieu muon theo ten nguoi muon
  {
    // Con tro ham get_name tro den ham Borrow::get_person_name()
    Borrow_memfnc_str get_name = &Borrow::get_person_name;

    // Sap xep danh sach phieu muon theo ten nguoi muon tang dan
    merge_sort<list<Borrow>, list<Borrow>::iterator, Borrow_memfnc_str>(borrows, borrows.begin(), --borrows.end(), get_name);
  }
  break;

  case 3: // Sap xep danh sach phieu muon theo ngay tra
  {
    // Con tro ham get_day_returned tro den ham Borrow::get_day_returned()
    Borrow_memfnc_str get_day_returned = &Borrow::get_day_returned;

    // Sap xep danh sach phieu muon theo ngay tra tang dan
    quick_sort<list<Borrow>::iterator, Borrow, Borrow_memfnc_str>(borrows.begin(), --borrows.end(), 0, borrows.size() - 1, get_day_returned);
  }
  break;

  case 0:
    break;

  default:
    break;
  }
}

// Thuc hien lua chon menu danh sach phieu muon
void display_borrowed_option()
{
  int choice;
  // Menu lua chon hien thi danh sach phieu muon
  menu_list_borrow_option();
  cout << "\n Nhap lua chon cua ban: ";
  cin >> choice;
  while (choice < 0 || choice > 3 || cin.fail())
  {
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    clear_screen(); // Xoa man hinh
    // Menu lua chon hien thi danh sach phieu muon
    menu_list_borrow_option();
    cout << "\n Nhap sai! Vui long nhap lai\n";
    cout << "\n Nhap lua chon cua ban: ";
    cin >> choice;
  }
  clear_screen(); // Xoa man hinh

  list<Borrow> borrows_read; // Luu danh sach phieu muon duoc doc tu file
  // Doc danh sach phieu muon tu file luu vao container borrows_read
  read_list_from_file<list<Borrow>, Borrow>(borrows_read, BORROW_FILE);

  switch (choice)
  {
  case 1: // Danh sach phieu dang muon
  {
    int sort_choice; // Lua chon sap xep hoac tro ve menu chinh
    string title = "\n DANH SACH PHIEU DANG MUON\n\n";

    // Thuc hien lua chon menu va sap xep danh sach phieu dang muon
    sort_borrows(borrows_read, title, sort_choice, choice);

    if (sort_choice)
    {
      cout << title;
      // Hien thi danh sach phieu dang muon
      display_borrowing_list(borrows_read);
      cin.get();
    }
  }
  break;

  case 2: // Danh sach phieu muon da tra
  {
    int sort_choice; // Lua chon sap xep hoac tro ve menu chinh
    string title = "\n DANH SACH PHIEU DA TRA\n\n";

    // Thuc hien lua chon menu va sap xep danh sach phieu da tra
    sort_borrows(borrows_read, title, sort_choice, choice);

    if (sort_choice)
    {
      cout << title;
      // Hien thi danh sach phieu muon da tra
      display_returned_list(borrows_read);
      cin.get();
    }
  }
  break;

  case 3: // Tat ca danh sach
  {
    cout << "\n DANH SACH PHIEU DANG MUON\n\n";
    // Xuat danh sach phieu dang muon
    display_borrowing_list(borrows_read);

    cout << endl;

    cout << "\n DANH SACH PHIEU DA TRA\n\n";
    // Xuat danh sach phieu muon da tra da
    display_returned_list(borrows_read);

    cin.get();
  }
  break;

    // Tro ve menu chinh khi nhap 0
  case 0:
    break;

  default:
    break;
  }
}

// Xuat danh sach phieu dang muon
void display_borrowing_list(list<Borrow> borrows)
{
  Borrow borrow;
  // Hien thi tieu de danh sach phieu dang muon
  borrow.title_borrowing_list();

  // Xuat danh sach phieu muon co trang thai "Dang muon"
  display_borrow_list(borrows, "Dang muon");

  cout << " " << setfill('=') << setw(140) << "=" << setfill(' ') << endl;
}

// Xua danh sach phieu muon da tra
void display_returned_list(list<Borrow> borrows)
{
  Borrow borrow;
  // Hien thi tieu de danh sach phieu muon da tra
  borrow.title_list();

  // Xuat danh sach phieu muon co trang thai "Da tra"
  display_borrow_list(borrows, "Da tra");

  cout << " " << setfill('=') << setw(167) << "=" << setfill(' ') << endl;
}

// Thay doi so luong sach sau khi tao phieu muon hoac tra sach
// Thay doi trong container books
// voi sach co ma sach book_id
// n = 1 khi tra sach thanh cong
// n = -1 khi tao phieu muon thanh cong
// Ghi danh sach sach tu container books
// sau khi thay doi so luong sach thanh cong vao file TEMP_BOOK_FILE
void change_amount(list<Book> &books, string book_id, int n)
{
  list<Book>::iterator it;
  for (it = books.begin(); it != books.end(); it++)
    if (it->get_book_id() == book_id)
    {
      it->set_amount(it->get_amount() + n);
      break;
    }
  // Ghi danh sach sach tu container books vao file TEMP_BOOK_FILE
  write_list_to_file<list<Book>, list<Book>::iterator>(books, TEMP_BOOK_FILE);
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
void change_borrow(list<Borrow> &borrows, Borrow &borrow)
{
  list<Borrow>::iterator it;
  for (it = borrows.begin(); it != borrows.end(); it++)
    // Neu tim thay dung ma phieu muon thi thuc hien thay doi
    // thong tin phieu muon
    if (it->get_borrow_id() == borrow.get_borrow_id())
    {
      // Gan ngay tra vao phieu muon
      it->set_day_returned(borrow.get_day_returned());

      // Gan tinh trang sach khi tra vao phieu muon
      it->set_status_returned_book(borrow.get_status_returned_book());

      // Thay doi trang thai phieu muon thanh Da tra
      it->set_borrow_status(borrow.get_borrow_status());

      // Gan ma sach da tra tro lai phieu muon da nhap
      // de thuc hien tang so luong sach da tra
      borrow.set_book_id(it->get_book_id());
      break;
    }
  // Ghi danh sach phieu muon da thay doi thong tin cao file TEMP_BORROW_FILE
  write_list_to_file<list<Borrow>, list<Borrow>::iterator>(borrows, TEMP_BORROW_FILE);

  // Xoa file BORROW_FILE cu
  remove(BORROW_FILE);

  // Doi ten file TEMP_BORROW_FILE da thay doi thong tin phieu muon
  // thanh BORROW_FILE
  rename(TEMP_BORROW_FILE, BORROW_FILE);
}

// Nhap thong tin sach/phieu muon
template <class Container, class Obj>
void input_info(Container &container, string file_name)
{
  Obj obj;
  obj.input_an_info();      // Goi ham nhap thong tin cho sach/phieu muon
  container.push_back(obj); // Luu thong tin vua nhap vao contain

  // Ghi thong tin vua nhap vao file
  write_info_to_file<Container>(container, file_name);
}

// Ghi thong tin sach/phieu muon vua nhap vao file
template <class Container>
void write_info_to_file(Container container, string file_name)
{
  ofstream out_file;
  try
  {
    out_file.open(file_name, ios::app | ios::binary);
    if (!out_file)
      throw "  Loi mo file ";
    // Luu thong tin da nhap vao file
    out_file.write(reinterpret_cast<char *>(&container.back()),
                   sizeof(container.back()));
  }
  catch (const char *str_error)
  {
    cout << str_error << file_name << endl;
    return;
  }
  catch (...)
  {
    cerr << "  Loi ghi file " << file_name;
  }
  out_file.close();
}

// Ghi sanh sach thong tin sach/phieu muon tu container vao file
template <class Container, class It>
void write_list_to_file(Container container, string file_name)
{
  ofstream out_file;
  try
  {
    out_file.open(file_name, ios::app | ios::binary);
    if (!out_file)
      throw "  Loi mo file ";
    // Luu thong tin sach vao file
    It it;
    for (it = container.begin(); it != container.end(); it++)
      out_file.write(reinterpret_cast<char *>(&*it), sizeof(*it));
  }
  catch (const char *str_error)
  {
    cout << str_error << file_name << endl;
    return;
  }
  catch (...)
  {
    cerr << "  Loi ghi file " << file_name;
  }
  out_file.close();
}

// Doc danh sach sach/phieu muon tu file
// Luu vao container
template <class Container, class Obj>
void read_list_from_file(Container &container, string file_name)
{
  ifstream in_file;
  try
  {
    in_file.open(file_name, ios::app | ios::binary);
    if (!in_file)
      throw "  Loi mo file ";
    Obj obj;
    while (in_file.read(reinterpret_cast<char *>(&obj), sizeof(obj)))
    {
      // Luu vao container
      container.push_back(obj);
    }
  }
  catch (const char *str_error)
  {
    cout << str_error << file_name << endl;
    return;
  }
  catch (...)
  {
    cerr << "  Loi doc file " << file_name;
  }
  in_file.close();
}

// Hien thi danh sach sach
template <class Container, class It, class Obj>
void display_list(Container container)
{
  // Hien thi tieu de danh sach sach
  Obj obj;
  obj.title_list();
  It it;
  int i = 0;
  for (it = container.begin(); it != container.end(); it++)
  {
    i++;
    // Hien thi thong tin sach
    it->display_an_info(i);
  }
}

// Xuat danh sach phieu muon theo trang thai
void display_borrow_list(list<Borrow> borrows, string status)
{
  list<Borrow>::iterator it;
  int i = 0;
  for (it = borrows.begin(); it != borrows.end(); it++)
    if (it->get_borrow_status() == status)
    {
      i++;
      if (status == "Dang muon")
        // Hien thi thong tin phieu muon neu status la Dang muon
        it->display_borrowing(i);
      else if (status == "Da tra")
        // Hien thi thong tin phieu muon neu status la Da tra
        it->display_an_info(i);
    }
}

// Hoan doi
template <class It, class Obj>
void my_swap(It a, It b)
{
  Obj temp = *a;
  *a = *b;
  *b = temp;
}

// Sap xep noi bot - Bubble sort
template <class Container, class It, class Obj, class Mem_func>
void bubble_sort(Container &container, Mem_func mem_func)
{
  It it_i, it_j;
  It last = container.end();
  --last;
  for (int i = 1; i < container.size(); i++)
  {
    --last;
    for (it_i = container.begin(); it_i != last; it_i++)
    {
      it_j = it_i;
      ++it_j;
      if (((*it_i).*mem_func)() > ((*it_j).*mem_func)())
        my_swap<It, Obj>(it_i, it_j);
    }
  }
}

// Sap xep chon - Selection sort
template <class Container, class It, class Obj, class Mem_func>
void selection_sort(Container &container, Mem_func mem_func)
{
  bool check;
  It min;
  It it_i, it_j;
  for (it_i = container.begin(); it_i != container.end(); it_i++)
  {
    check = false;
    min = it_i;
    it_j = min;
    for (++it_j; it_j != container.end(); it_j++)
    {
      if (((*it_j).*mem_func)() < ((*min).*mem_func)())
      {
        min = it_j;
        check = true;
      }
    }
    if (check)
      my_swap<It, Obj>(it_i, min);
  }
}

// Sap xep chen - Insertion sort
template <class Container, class It, class Obj, class Mem_func>
void insertion_sort(Container &container, Mem_func mem_func)
{
  It it_i = container.begin();
  It it_j, it_k;
  for (++it_i; it_i != container.end(); it_i++)
  {
    it_j = it_i;
    it_k = it_j;
    --it_k;

    while (it_j != container.begin() && ((*it_k).*mem_func)() >
                                            ((*it_j).*mem_func)())
    {
      my_swap<It, Obj>(it_k, it_j);
      --it_j;
      if (it_j != container.begin())
      {
        it_k = it_j;
        --it_k;
      }
    }
  }
}

// Tron 2 phan thanh mot container duoc sap xep
template <class Container, class It, class Mem_func>
void merge(Container &container, It from, It to, It mid, Mem_func mem_func)
{
  It i = from;
  It j = ++mid;
  Container temps;
  ++to;

  // Tron 2 phan vao container temps
  while (i != mid && j != to)
  {
    if (((*i).*mem_func)() < ((*j).*mem_func)())
    {
      temps.push_back(*i);
      i++;
    }
    else
    {
      temps.push_back(*j);
      j++;
    }
  }

  // Chen tat ca cac gia tri con lai tu i toi mid vao container temps
  while (i != mid)
  {
    temps.push_back(*i);
    i++;
  }

  // Chen tat ca cac gia tri con lai tu j toi cuoi vao container temps
  while (j != to)
  {
    temps.push_back(*j);
    j++;
  }

  // Gan du lieu da duoc sap xep tu temps vao container a
  It it_temps;
  for (it_temps = temps.begin(); it_temps != temps.end(); it_temps++)
  {
    *from = *it_temps;
    from++;
  }
}

// Sap xep tron - Merge sort
template <class Container, class It, class Mem_func>
void merge_sort(Container &container, It from, It to, Mem_func mem_func)
{
  It mid;
  if (from != to)
  {
    int count;
    mid = from;
    It jump = from;
    for (count = 1; jump != to; jump++)
      ++count;

    for (int i = 1; i < count / 2; i++)
      ++mid;

    merge_sort(container, from, mid, mem_func);
    merge_sort(container, ++mid, to, mem_func);

    merge<Container, It, Mem_func>(container, from, to, --mid, mem_func);
  }
}

// Sap xep nhanh - Quick sort
template <class It, class Obj, class Mem_func>
void quick_sort(It left, It right, int p_l, int p_r, Mem_func mem_func)
{
  It l = left;
  It r = right;
  int p_left = p_l;
  int p_right = p_r;

  // Tim mid
  It pivot = left;
  for (int i = p_l; i < (p_l + p_r) / 2; i++)
    ++pivot;

  while (p_l <= p_r)
  {
    while (((*l).*mem_func)() < ((*pivot).*mem_func)())
    {
      l++;
      p_l++;
    }

    while (((*r).*mem_func)() > ((*pivot).*mem_func)())
    {
      r--;
      p_r--;
    }

    if (p_l <= p_r)
    {
      my_swap<It, Obj>(l, r);
      l++;
      p_l++;
      r--;
      p_r--;
    }
  }
  if (p_left < p_r)
    quick_sort<It, Obj, Mem_func>(left, r, p_left, p_r, mem_func);
  if (p_l < p_right)
    quick_sort<It, Obj, Mem_func>(l, right, p_l, p_right, mem_func);
}

// Tim kiem tuyen tinh - Linear search
template <class Container, class It, class Key, class Mem_func>
void linear_search(Container container, Key key, Container &result, Mem_func mem_func)
{
  It it;
  int count = 0;
  for (it = container.begin(); it != container.end(); it++)
    if (((*it).*mem_func)() == key)
    {
      count++;
      result.push_back(*it);
    }
  if (count == 0)
    cout << "\n Ket qua: Khong tim thay!\n";
}

// Tim kiem nhi phan - Binary search
template <class Container, class It, class Key, class Mem_func>
void binary_search(Container container, Key key, Container &result, Mem_func mem_func)
{
  bool check = false;
  It first = container.begin();
  It last = --container.end();
  int p_first = 0;
  int p_last = container.size() - 1;
  while (p_first <= p_last)
  {
    int p_mid = p_first;
    It mid = first;
    for (int i = p_first + 1; i <= (p_first + p_last) / 2; i++)
    {
      ++mid;
      ++p_mid;
    }

    if (((*mid).*mem_func)() == key)
    {
      check = true;
      result.push_back(*mid);
      break;
    }
    else if (key < ((*mid).*mem_func)())
    {
      last = --mid;
      p_last = --p_mid;
    }
    else if (key > ((*mid).*mem_func)())
    {
      first = ++mid;
      p_first = ++p_mid;
    }
  }
  if (!check)
    cout << "\n Ket qua: Khong tim thay!\n";
}

// Xoa man hinh
// dung lenh cls voi Windows (WIN32/WIN64)
// dung lenh clear voi unix
void clear_screen()
{
#ifdef _WIN32
  system("cls");
#endif // _WIN32

#ifdef _WIN64
  system("cls");
#endif // _WIN64

#ifdef __unix__
  system("clear");
#endif // __unix__
}