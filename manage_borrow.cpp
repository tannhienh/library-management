#include "manage_borrow.h"

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
  cout << "\n 1. Sap xep theo tieu de sach";
  cout << "\n 2. Sap xep theo nam xuat ban";
  cout << "\n 3. Sap xep theo nha xuat ban";
  cout << "\n 4. Sap xep theo tac gia";
  cout << "\n 5. Sap xep theo sach moi nhat";
  cout << "\n 0. Tro ve\n";
}

// Menu lua chon hien thi danh sach phieu muon
void menu_list_borrow_option()
{
  cout << "\n DANH SACH PHIEU MUON\n";
  cout << "\n 1. Danh sach phieu dang muon";
  cout << "\n 2. Danh sach phieu muon da tra";
  cout << "\n 3. Tat ca danh sach";
  cout << "\n 0. Tro ve\n";
}

// Hien thi menu tim kiem
void menu_search_option()
{
  cout << "\n TIM KIEM\n";
  cout << "\n 1. Sach";
  cout << "\n 2. Phieu muon";
  cout << "\n 0. Tro ve\n";
}

// Hien thi menu tim kiem sach
void menu_search_book()
{
  cout << "\n TIM KIEM SACH\n";
  cout << "\n 1. Theo ma nguoi muon";
  cout << "\n 2. Theo ten nguoi muon";
  cout << "\n 3. Theo ngay muon";
  cout << "\n 4. Theo ngay tra";
  cout << "\n 5. Theo tinh trang sach";
  cout << "\n 0. Tro ve menu chinh\n";
}

// Hien thi menu tim kiem phieu muon
void menu_search_borrow()
{
  cout << "\n TIM KIEM PHIEU MUON\n";
  cout << "\n 1. Theo ma sach";
  cout << "\n 2. Theo tieu de sach";
  cout << "\n 3. Theo nam xuat ban";
  cout << "\n 4. Theo tac gia";
  cout << "\n 5. Theo The loai";
  cout << "\n 0. Tro ve menu chinh\n";
}

// Hien thi menu Sap xep phieu dang muon
void menu_sort_borrowing()
{
  cout << " 1. Sap xep theo ngay muon";
  cout << "\n 2. Sap xep theo ten nguoi muon";
  cout << "\n 0. Tro ve menu chinh\n";
}

// Hien thi menu Sap xep phieu muon da tra
void menu_sort_returned()
{
  cout << " 1. Sap xep theo ngay muon";
  cout << "\n 2. Sap xep theo ten nguoi muon";
  cout << "\n 3. Sap xep theo ngay tra";
  cout << "\n 0. Tro ve menu chinh\n";
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
  write_list_to_file<list<Book>, list<Book>::iterator>(books,
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
      // de thuc hien tang so luong sach da nhap
      borrow.set_book_id(it->get_book_id());
      break;
    }
  // Ghi danh sach phieu muon da thay doi thong tin cao file TEMP_BORROW_FILE
  write_list_to_file<list<Borrow>, list<Borrow>::iterator>(
      borrows, TEMP_BORROW_FILE);

  // Xoa file BORROW_FILE cu
  remove(BORROW_FILE);

  // Doi ten file TEMP_BORROW_FILE da thay doi thong tin phieu muon
  // thanh BORROW_FILE
  rename(TEMP_BORROW_FILE, BORROW_FILE);
}

// Ghi sanh sach thong tin sach/phieu muon tu container vao file
template <typename container, typename iterator>
void write_list_to_file(container contain, string file_name)
{
  ofstream out_file;
  try
  {
    out_file.open(file_name, ios::app | ios::binary);
    if (!out_file)
      throw "  Loi mo file ";
    // Luu thong tin sach vao file
    iterator it;
    for (it = contain.begin(); it != contain.end(); it++)
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

// Xu ly lua chon menu chinh tu nguoi dung
void main_menu()
{
  int menu_choice;
  list<Book> books_write;     // Chua danh sach sach da nhap de luu vao file
  list<Borrow> borrows_write; // Chua danh sach phieu muon de luu vao file
  do
  {
    clear_screen();
    menu_main_option();
    cout << "\n Nhap lua chon cua ban: ";
    cin >> menu_choice;

    // Neu lua chon menu sai (0 > choice > 5)
    // se thong bao nhap sai va yeu cau nhap lai
    while (menu_choice < 0 || menu_choice > 6 || cin.fail())
    {
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      clear_screen();
      menu_main_option();
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
      input_info<list<Book>, Book>(books_write, BOOK_FILE, book);
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

      while (choice < 0 || choice > 5 || cin.fail())
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
        list<Book> books_read; // luu danh sach sach doc duoc tu file
        Book book;
        cout << " " << setfill('=') << setw(127) << "=" << setfill(' ') << endl;
        // Hien thi tieu de danh sach sach
        book.title_books_list();
        cout << " " << setfill('-') << setw(127) << "-" << setfill(' ') << endl;

        // Doc danh sach sach tu file luu vao container books_read
        read_list_from_file<list<Book>, Book>(books_read, BOOK_FILE);

        switch (choice)
        {
        case 1:
          // Sap xep danh sach sach trong books_read theo tieu de sach
          books_read.sort(compare_title);
          break;

        case 2:
          // Sap xep danh sach sach trong books_read theo nam xuat ban
          books_read.sort(compare_year);
          break;

        case 3:
          // Sap xep danh sach sach trong books_read theo nha xuat ban
          books_read.sort(compare_publisher);
          break;

        case 4:
          // Sap xep danh sach sach trong books_read theo ten tac gia
          books_read.sort(compare_author);
          break;

        case 5:
          // Sap xep danh sach sach trong books_read theo sach moi nhat
          reverse(books_read.begin(), books_read.end());
          break;

        default:
          break;
        }

        // Xuat danh sach da sap xep trong books_read ra man hinh
        book.display_book_list(books_read);

        cout << " " << setfill('=') << setw(127) << "=" << setfill(' ') << endl;
        cin.get();
      }
    }
    break;

    case 3:
    {
      cout << "\n NHAP THONG TIN PHIEU MUON SACH\n\n";

      Borrow borrow;
      // Nhap thong tin phieu muon roi luu vao container borrows_write
      input_info<list<Borrow>, Borrow>(borrows_write, BORROW_FILE, borrow);

      // Doc danh sach sach tu file luu vao container books_read
      list<Book> books_read;
      read_list_from_file<list<Book>, Book>(books_read, BOOK_FILE);

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
      list<Borrow> borrows_read;
      read_list_from_file<list<Borrow>, Borrow>(borrows_read, BORROW_FILE);

      // Thay doi thong tin phieu muon khi tra sach
      change_borrow(borrows_read, borrow);
      cout << "\n Nhap thong tin thanh cong!\n";

      // Doc danh sach sach tu file luu vao container books_read
      list<Book> books_read;
      read_list_from_file<list<Book>, Book>(books_read, BOOK_FILE);

      // Tang so luong cua sach da tra len 1
      change_amount(books_read, borrow.get_book_id(), 1);
      cin.get();
    }
    break;

    case 5:
    {
      display_borrowed_option();
    }
    break;

    case 6:
    {
      // Hien thi menu tim kiem
      search_option();
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
    clear_screen();
    // Menu lua chon hien thi danh sach phieu muon
    menu_list_borrow_option();
    cout << "\n Nhap sai! Vui long nhap lai";
    cout << "\n Nhap lua chon cua ban: ";
    cin >> choice;
  }
  clear_screen();

  list<Borrow> borrows_read; // Luu danh sach phieu muon duoc doc tu file
  // Doc danh sach phieu muon tu file luu vao container borrows_read
  read_list_from_file<list<Borrow>, Borrow>(borrows_read, BORROW_FILE);

  switch (choice)
  {
  case 1:
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

  case 2:
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

  case 3:
  {
    // Sap xep danh sach phieu muon theo ngay muon tang dan
    borrows_read.sort(compare_day_borrowed);

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

// Tim kiem sach
void search_book()
{
  int choice;
  menu_search_book();
  cout << "\n Nhap lua chon cua ban: ";
  cin >> choice;
  while (choice < 0 || choice > 5 || cin.fail())
  {
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    clear_screen();
    // Menu lua chon hien thi danh sach phieu muon
    menu_search_book();
    cout << "\n Nhap sai! Vui long nhap lai";
    cout << "\n Nhap lua chon cua ban: ";
    cin >> choice;
  }
  clear_screen();

  switch (choice)
  {
  case 1:
  {
    
  }
  break;

  case 2:
  {
  }
  break;

  case 3:
  {
  }
  break;

  case 4:
  {
  }
  break;

  case 5:
  {
  }
  break;

  case 0:
    break;

  default:
    break;
  }
}

// Tim kiem phieu muon
void search_borrow()
{
  int choice;
  menu_search_borrow();
  cout << "\n Nhap lua chon cua ban: ";
  cin >> choice;
  while (choice < 0 || choice > 5 || cin.fail())
  {
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    clear_screen();
    // Menu lua chon hien thi danh sach phieu muon
    menu_search_borrow();
    cout << "\n Nhap sai! Vui long nhap lai";
    cout << "\n Nhap lua chon cua ban: ";
    cin >> choice;
  }
  clear_screen();

  switch (choice)
  {
  case 1:
  {
  }
  break;

  case 2:
  {
  }
  break;

  case 3:
  {
  }
  break;

  case 4:
  {
  }
  break;

  case 5:
  {
  }
  break;

  case 0:
    break;

  default:
    break;
  }
}

// Thuc hien chuc nang tim kiem
void search_option()
{
  int choice;
  menu_search_option();
  cout << "\n Nhap lua chon cua ban: ";
  cin >> choice;
  while (choice < 0 || choice > 2 || cin.fail())
  {
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    clear_screen();
    // Menu lua chon hien thi danh sach phieu muon
    menu_search_option();
    cout << "\n Nhap sai! Vui long nhap lai";
    cout << "\n Nhap lua chon cua ban: ";
    cin >> choice;
  }
  clear_screen();

  if (choice == 0)
    return;
  if (choice == 1)
    search_book();
  if (choice == 2)
    search_borrow();
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
      clear_screen();
      cout << title;
      // Menu lua chon sap xep danh sach phieu muon da tra
      menu_sort_borrowing();
      cout << "\n Nhap sai! Vui long nhap lai";
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
      clear_screen();
      cout << title;
      // Menu lua chon sap xep danh sach phieu muon da tra
      menu_sort_returned();
      cout << "\n Nhap sai! Vui long nhap lai";
      cout << "\n Nhap lua chon cua ban: ";
      cin >> choice;
    }
  }

  clear_screen();

  switch (choice)
  {
  case 1:
    // Sap xep danh sach phieu muon theo ngay muon tang dan
    borrows.sort(compare_day_borrowed);
    break;

  case 2:
    // Sap xep danh sach phieu muon theo ten nguoi muon tang dan
    borrows.sort(compare_person_name);
    break;

  case 3:
    // Sap xep danh sach phieu muon theo ngay tra tang dan
    borrows.sort(compare_day_returned);
    break;

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
  cout << " " << setfill('=') << setw(140) << "=" << setfill(' ') << endl;
  // Hien thi tieu de danh sach phieu dang muon
  borrow.title_borrowing_list();
  cout << " " << setfill('-') << setw(140) << "-" << setfill(' ') << endl;

  // Xuat danh sach phieu muon co trang thao dang muon
  borrow.display_borrow_list(borrows, "Dang muon");

  cout << " " << setfill('=') << setw(140) << "=" << setfill(' ') << endl;
}

// Xua danh sach phieu muon da tra
void display_returned_list(list<Borrow> borrows)
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

// So sanh theo nha xuat ban
bool compare_publisher(Book first, Book second)
{
  return (first.get_publisher() < second.get_publisher());
}

// So sanh theo tac gia
bool compare_author(Book first, Book second)
{
  return (first.get_author() < second.get_author());
}

// So sanh theo ngay muon sach
bool compare_day_borrowed(Borrow first, Borrow second)
{
  return (first.get_day_borrowed() < second.get_day_borrowed());
}

// So sanh theo ten nguoi muon
bool compare_person_name(Borrow first, Borrow second)
{
  return (first.get_person_name() < second.get_person_name());
}

// So sanh theo ngay tra
bool compare_day_returned(Borrow first, Borrow second)
{
  return (first.get_day_returned() < second.get_day_returned());
}

// Nhap thong tin sach/phieu muon
template <typename container, typename T>
void input_info(container &contain, string file_name, T &t)
{
  t.input_an_info();    // Goi ham nhap thong tin cho sach/phieu muon
  contain.push_back(t); // Luu thong tin vua nhap vao contain

  // Ghi thong tin vua nhap vao file
  write_info_to_file<container>(contain, file_name);
}

// Ghi thong tin sach/phieu muon vua nhap vao file BOOK_FILE/BORROW_FILE
template <typename container>
void write_info_to_file(container contain, string file_name)
{
  ofstream out_file;
  try
  {
    out_file.open(file_name, ios::app | ios::binary);
    if (!out_file)
      throw "  Loi mo file ";
    // Luu thong tin da nhap vao file
    out_file.write(reinterpret_cast<char *>(&contain.back()),
                   sizeof(contain.back()));
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
// Luu vao contain
template <typename container, typename T>
void read_list_from_file(container &contain, string file_name)
{
  ifstream in_file;
  try
  {
    in_file.open(file_name, ios::app | ios::binary);
    if (!in_file)
      throw "  Loi mo file ";
    T t;
    while (in_file.read(reinterpret_cast<char *>(&t), sizeof(t)))
    {
      // Luu vao cuoi container contain
      contain.push_back(t);
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