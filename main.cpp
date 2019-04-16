//---------------------------------------------------------------------------//
// Application console Manage Library
// Compiler: g++, MSVS
//---------------------------------------------------------------------------//

#include "borrow.h"        // File quan ly phieu muon
#include "manage_borrow.h" // File quan ly muon sach

void main_menu();                            // Hien thi menu chinh
void menu_list_book_option();                // Menu lua chon kieu sap xep danh sach sach
void menu_borrow_option();                   // Menu lua chon hien thi danh sach phieu muon
void main_menu_option();                     // Thuc hien cac lua chon menu chinh
void display_borrowed_option();              // Thuc hien lua chon menu
                                             // danh sach phieu muon
void display_borrowing_list(vector<Borrow>); // Xuat danh sach phieu dang muon
void display_returned_list(vector<Borrow>);  // Xuat danh sach phieu da tra
bool compare_title(Book, Book);              // So sanh tieu de sach
bool compare_year(Book, Book);               // So sanh nam xuat ban
bool compare_day_borrowed(Borrow, Borrow);   // So sanh ngay muon sach
void clear_screen();                         // Xoa man hinh

//====================================================//
// HAM MAIN
//====================================================//
int main()
{
  try
  {
    main_menu_option(); // Thuc hien lua chon menu chinh
  }
  catch (exception &e)
  {
    // Bat loi neu co bat cu loi nao
    cerr << "\nLoi: " << e.what() << endl;
  }
  catch (...)
  {
    cerr << "\nLoi ngoai le!\n";
  }

  cin.get();
  return 0;
}
//====================================================//

// Hien thi menu chinh
void main_menu()
{
  cout << "\n CHUONG TRINH QUAN LY THU VIEN\n";
  cout << "\n ============================================";
  cout << "\n\n Moi ban chon";
  cout << "\n\n 1. Nhap thong tin sach.";
  cout << "\n\n 2. Danh sach thong tin sach.";
  cout << "\n\n 3. Muon sach.";
  cout << "\n\n 4. Tra sach.";
  cout << "\n\n 5. Danh sach phieu muon sach.";
  cout << "\n\n 0. Thoat.";
  cout << "\n\n ============================================\n";
}

// Menu lua chon kieu sap xep danh sach sach
void menu_list_book_option()
{
  cout << "\n DANH SACH THONG TIN SACH\n\n";
  cout << "\n 1. Sap xep theo tieu de sach";
  cout << "\n 2. Sap xep theo nam xuat ban";
  cout << "\n 3. Sap xep theo sach moi nhat";
  cout << "\n 0. Tro ve\n";
}

// Xu ly lua chon menu chinh tu nguoi dung
void main_menu_option()
{
  int menu_choice;
  vector<Book> books_write;     // Chua danh sach sach da nhap de luu vao file
  vector<Borrow> borrows_write; // Chua danh sach phieu muon de luu vao file
  do
  {
    clear_screen();
    main_menu();
    cout << "\n Nhap lua chon cua ban: ";
    cin >> menu_choice;

    // Neu lua chon menu sai (0 > choice > 5)
    // se thong bao nhap sai va yeu cau nhap lai
    while (menu_choice < 0 || menu_choice > 5 || cin.fail())
    {
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      clear_screen();
      main_menu();
      cout << "\n Nhap sai! vui long nhap lai.\n";
      cout << "\n Nhap lua chon cua ban: ";
      cin >> menu_choice;
    }

    clear_screen();

    switch (menu_choice)
    {
    case 1:
    {
      cout << "\n NHAP THONG TIN SACH\n\n";
      Book book;
      // Nhap thong tin sach
      input_info<vector<Book>, Book>(books_write, BOOK_FILE, book);
      cout << "\n Luu thong tin thanh cong!\n";
      cin.get();
    }
    break;

    case 2:
    {
      int choice;
      menu_list_book_option();
      cout << "\n Nhap lua chon cua ban: ";
      cin >> choice;

      while (choice < 0 || choice > 3 || cin.fail())
      {
        if (cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        clear_screen();
        menu_list_book_option();
        cout << "\n Nhap sai! Vui long nhap lai";
        cout << "\n Nhap lua chon cua ban: ";
        cin >> choice;
      }

      // Tro ve menu chinh khi chon 0
      if (choice == 0)
        break;
      else
      {
        clear_screen();
        cout << "\n DANH SACH THONG TIN SACH\n\n";
        vector<Book> books_read; // luu danh sach sach doc duoc tu file
        Book book;
        cout << " " << setfill('=') << setw(127) << "=" << setfill(' ') << endl;
        // Hien thi tieu de danh sach sach
        book.title_books_list();
        cout << " " << setfill('-') << setw(127) << "-" << setfill(' ') << endl;

        // Doc danh sach sach tu file luu vao container books_read
        read_list_from_file<vector<Book>, Book>(books_read, BOOK_FILE);

        if (choice == 1)
          // Sap xep danh sach sach trong books_read theo tieu de sach
          sort(books_read.begin(), books_read.end(), compare_title);
        else if (choice == 2)
          // Sap xep danh sach sach trong books_read theo nam
          sort(books_read.begin(), books_read.end(), compare_year);
        else if (choice == 3)
          // Sap xep danh sach sach trong books_read theo sach moi nhat
          reverse(books_read.begin(), books_read.end());

        // Xuat danh sach da sap xep trong books_read ra man hinh
        book.display_book_list(books_read);
      }

      cout << " " << setfill('=') << setw(127) << "=" << setfill(' ') << endl;
      cin.get();
    }
    break;

    case 3:
    {
      cout << "\n NHAP THONG TIN PHIEU MUON SACH\n\n";

      Borrow borrow;
      // Nhap thong tin phieu muon roi luu vao container borrows_write
      input_info<vector<Borrow>, Borrow>(borrows_write, BORROW_FILE, borrow);

      // Doc danh sach sach tu file luu vao container books_read
      vector<Book> books_read;
      read_list_from_file<vector<Book>, Book>(books_read, BOOK_FILE);

      // Giam so luong sach da muon di 1
      change_amount(books_read, borrow.get_book_id(), -1);

      cout << "\n Nhap thong tin thanh cong!\n";
      cin.get();
    }
    break;

    case 4:
    {
      cout << "\n NHAP THONG TIN TRA SACH\n\n";

      // Nhap thong tin tra sach
      Borrow borrow;
      borrow.input_return();

      // Doc danh sach phieu muon tu file luu vao container borrows_read
      vector<Borrow> borrows_read;
      read_list_from_file<vector<Borrow>, Borrow>(borrows_read, BORROW_FILE);

      // Thay doi thong tin phieu muon khi tra sach
      change_borrow(borrows_read, borrow);
      cout << "\n Nhap thong tin thanh cong!\n";

      // Doc danh sach sach tu file luu vao container books_read
      vector<Book> books_read;
      read_list_from_file<vector<Book>, Book>(books_read, BOOK_FILE);

      // Tang so luong cua sach da tra len 1
      change_amount(books_read, borrow.get_book_id(), 1);
      cin.get();
    }
    break;

    case 5:
    {
      // Thuc hien lua chon menu danh sach phieu muon
      display_borrowed_option();
    }
    break;

      // Thoat khi nhap 0
    case 0:
      return;
      break;

    default:
      break;
    }
    cin.ignore();

  } while (menu_choice != 0);
}

// Menu lua chon hien thi danh sach phieu muon
void menu_borrow_option()
{
  cout << "\n Lua chon loai danh sach\n";
  cout << "\n 1. Danh sach phieu dang muon";
  cout << "\n 2. Danh sach phieu muon da tra";
  cout << "\n 3. Tat ca danh sach";
  cout << "\n 0. Tro ve\n";
}

// Thuc hien lua chon menu danh sach phieu muon
void display_borrowed_option()
{
  int choice;
  // Menu lua chon hien thi danh sach phieu muon
  menu_borrow_option();
  cout << "\n Nhap lua chon cua ban: ";
  cin >> choice;
  while (choice < 0 || choice > 3 || cin.fail())
  {
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    clear_screen();
    // Menu lua chon hien thi danh sach phieu muon
    menu_borrow_option();
    cout << "\n Nhap sai! Vui long nhap lai";
    cout << "\n Nhap lua chon cua ban: ";
    cin >> choice;
  }
  clear_screen();

  vector<Borrow> borrows_read; // Luu danh sach phieu muon duoc doc tu file
  // Doc danh sach phieu muon tu file luu vao container borrows_read
  read_list_from_file<vector<Borrow>, Borrow>(borrows_read, BORROW_FILE);

  // Sap xep danh sach phieu muon theo ngay muon tang dan
  sort(borrows_read.begin(), borrows_read.end(), compare_day_borrowed);
  switch (choice)
  {
  case 1:
  {
    cout << "\n DANH SACH PHIEU DANG MUON\n\n";
    // Xuat danh sach phieu dang muon da duoc sap xep
    display_borrowing_list(borrows_read);
    cin.get();
  }
  break;

  case 2:
  {
    cout << "\n DANH SACH PHIEU DA TRA\n\n";
    // Xuat danh sach phieu muon da tra da duoc sap xep
    display_returned_list(borrows_read);
    cin.get();
  }
  break;

  case 3:
  {
    cout << "\n DANH SACH PHIEU DANG MUON\n\n";
    // Xuat danh sach phieu dang muon da duoc sap xep
    display_borrowing_list(borrows_read);

    cout << endl;

    cout << "\n DANH SACH PHIEU DA TRA\n\n";
    // Xuat danh sach phieu da tra da duoc sap xep
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
void display_borrowing_list(vector<Borrow> borrows)
{
  Borrow borrow;
  cout << " " << setfill('=') << setw(140) << "=" << setfill(' ') << endl;
  // Hien thi tieu de danh sach phieu dang muon
  borrow.title_borrowing_list();
  cout << " " << setfill('-') << setw(140) << "-" << setfill(' ') << endl;

  // Xuat danh sach phieu muon co trang thao dang muon
  borrow.display_borrow_list(borrows, "Dang muon");

  cout << " " << setfill('=') << setw(140) << "=" << setfill(' ') << endl;
}

// Xua danh sach phieu muon da tra
void display_returned_list(vector<Borrow> borrows)
{
  Borrow borrow;
  cout << " " << setfill('=') << setw(167) << "=" << setfill(' ') << endl;
  // Hien thi tieu de danh sach phieu muon da tra
  borrow.title_returned_list();
  cout << " " << setfill('-') << setw(167) << "-" << setfill(' ') << endl;

  // Xuat danh sach phieu muon co trang thai da tra
  borrow.display_borrow_list(borrows, "Da tra");

  cout << " " << setfill('=') << setw(167) << "=" << setfill(' ') << endl;
}

// So sanh tieu de sach
bool compare_title(Book first, Book second)
{
  return (first.get_book_title() < second.get_book_title());
}

// So sanh theo nam xuat ban
bool compare_year(Book first, Book second)
{
  return (first.get_year() < second.get_year());
}

// So sanh theo ngay muon sach
bool compare_day_borrowed(Borrow first, Borrow second)
{
  return (first.get_day_borrowed() < second.get_day_borrowed());
}

// Xoa man hinh
// Phat hien OS
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