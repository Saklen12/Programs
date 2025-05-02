#include <iostream>
#include <string.h>
using namespace std;

// Creating Book class
class Book {
private:
    char *title;
    char *author;
    int pageCount;
    bool format;
    float *chapterPages;
    int chapters;

public:
    // Default constructor
    Book() {
        title = new char[1];
        title[0] = '\0';
        author = new char[1];
        author[0] = '\0';
        pageCount = 0;
        format = false;
        chapterPages = nullptr;
        chapters = 0;
    }

    // Parameterized constructor
    Book(const char* t, const char* a, int count, bool type, int chapter) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        author = new char[strlen(a) + 1];
        strcpy(author, a);
        pageCount = count;
        format = type;
        chapters = chapter;
        chapterPages = new float[chapter];

        for (int i = 0; i < chapter; i++) {
            chapterPages[i] = static_cast<float>(pageCount) / chapter;
        }
    }

    // Copy constructor (Deep Copy)
    Book(const Book& obj) {
        title = new char[strlen(obj.title) + 1];
        strcpy(title, obj.title);
        author = new char[strlen(obj.author) + 1];
        strcpy(author, obj.author);
        pageCount = obj.pageCount;
        format = obj.format;
        chapters = obj.chapters;

        if (obj.chapterPages) {
            chapterPages = new float[chapters];
            for (int i = 0; i < chapters; i++) {
                chapterPages[i] = obj.chapterPages[i];
            }
        } else {
            chapterPages = nullptr;
        }
    }

    // Modify page count in a specific chapter
    void modifyPageCount(int chapter_no, int pages) {
        if (chapter_no >= 0 && chapter_no < chapters) {
            chapterPages[chapter_no] = pages;
        } else {
            cout << "Chapter not available." << endl;
        }
    }

    // Display book details
    void display() {
        cout << "------- Book Information -------" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Total Pages: " << pageCount << endl;
        cout << "Format: " << (format ? "Hardcover" : "Paperback") << endl;
        cout << "Chapters: " << chapters << endl;

        if (chapterPages != nullptr) {
            cout << "Pages per chapter: ";
            for (int i = 0; i < chapters; i++) {
                cout << chapterPages[i] << " ";
            }
            cout << endl;
        } else {
            cout << "No pages in book." << endl;
        }
        cout << "-------------------------------" << endl;
    }

    // Destructor
    ~Book() {
        delete[] title;
        delete[] author;
        delete[] chapterPages;
    }
};

int main() {
    // Default constructor
    Book b1;
    cout << "\nDefault Constructor:" << endl;
    b1.display();

    // Parameterized constructor
    Book b2("Wings of Fire", "APJ Abdul Kalam", 300, true, 5);
    cout << "\nParameterized Constructor:" << endl;
    b2.display();

    // Copy constructor
    Book b3(b2);
    cout << "\nCopy (Deep) Constructor:" << endl;
    b3.display();

    // Modify chapter pages
    b3.modifyPageCount(3, 20);
    cout << "\nAfter modifying chapter 3 page count:" << endl;
    b3.display();

    return 0;
}
