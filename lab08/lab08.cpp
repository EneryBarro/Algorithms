
#include <iostream>
#include <string>
#include <conio.h>
#include <conio.h>
using namespace std;



template<typename T>
class sublist {
    struct node {
        T     val;
        node* lst;
        node* next;
    };
private:
    node* lst;
public:
    sublist(void) :lst(NULL) {}
    ~sublist() {
        this->clear();
    }

    typedef node item;
    sublist(const sublist&);
    sublist& operator = (const sublist&);
public:

    item* add(const T& val) {
        item* p = new (std::nothrow) item();
        if (p == NULL)
            return NULL;

        p->lst = NULL;
        p->val = val;
        p->next = lst;
        lst = p;
        return p;
    }

    item* add(item*& parent, const T& val) {
        if (parent == NULL)
            return NULL;

        item* p = new (std::nothrow) item();
        if (p != NULL) {
            p->val = val;
            p->lst = NULL;
            p->next = parent->lst;
            parent->lst = p;
        }
        return p;
    }

    void clear(void) {
        if (lst != NULL)
            __clear(lst);
        lst = NULL;
    }

    void print(std::ostream& _out, const item* p) {
        if (lst != NULL)
            __print(_out, lst, 0);
    }

    item* begin(void) const {
        return lst;
    }
    item* begin(void) {
        return lst;
    }

private:

    void __clear(item* p) {
        item* t;
        while (p != NULL) {
            if (p->lst != NULL)
                __clear(p->lst);
            t = p;
            p = p->next;
            delete t;
        }
    }

    void __print(std::ostream& _out, const item* p, int n) {
        while (p != NULL) {
            for (int i = 0; i < n; ++i)
                _out << '\t';
            _out << p->val << std::endl;

            if (p->lst != NULL)
                __print(_out, p->lst, n + 1);
            p = p->next;
        }
    }
};


int main(void)
{
    setlocale(LC_CTYPE, "rus");
    typedef sublist<std::string> lstr;

    lstr lsub;
    lstr::item* p, * s, * s1;
    int operation = NULL;
    char change;
    do
    {
        printf(
            "\t\t1\t-\tГРУППА A\n"\
            "\t\t2\t-\tГРУППА Б\n"\
            "\t\t3\t-\tГРУППА В\n"\
            "\t\t4\t-\tВCE ГРУППЫ\n"\
            "\t\t5\t-\tОЧИСТИТЬ СПИСОК\n"\
            "\n\t\tESC\t-\tВЫЙТИ\n\n"\
            "\t\t\t- - >\t"
        );
        cin >> operation;
        switch (operation)
        {
        case 1:
        {
            p = lsub.add("");
            s = lsub.add(p, "Группа A");
            lsub.add(s, "Сергеев");
            lsub.add(s, "Петров");
            lsub.add(s, "Пенькова");

            lsub.print(cout, lsub.begin());
            break;
        }
        case 2:
        {
            p = lsub.add("");
            s = lsub.add(p, "Группа Б");
            lsub.add(s, "Иваненко");
            lsub.add(s, "Синельник");
            lsub.add(s, "Макаренко");

            lsub.print(cout, lsub.begin());
            break;
        }
        case 3:
        {
            p = lsub.add("");
            s = lsub.add(p, "Группа B");
            lsub.add(s, "Ливенцов");
            lsub.add(s, "Крючков");
            lsub.add(s, "Степанова");

            lsub.print(cout, lsub.begin());
            break;
        }
        case 4:
        {
            p = lsub.add("Группы");
            s = lsub.add(p, "Группа B");
            lsub.add(s, "Ливенцов");
            lsub.add(s, "Крючков");
            lsub.add(s, "Степанова");

            s = lsub.add(p, "Группа Б");
            lsub.add(s, "Иваненко");
            lsub.add(s, "Синельник");
            lsub.add(s, "Макаренко");

            s = lsub.add(p, "Группа A");
            lsub.add(s, "Сергеев");
            lsub.add(s, "Петров");
            lsub.add(s, "Пенькова");

            lsub.print(cout, lsub.begin());
            break;
        }
        case 5:
        {

            lsub.clear();
            printf("СПИСОК ОЧИЩЕН...");
            break;
        }
        }

    start: cout << "\nContinue?(y/n)";
        cin >> change; cout << endl;
        if (change == 'y')
            continue;
        else if (change == 'n')
            exit(0);
    } while (operation != 'n');
    _getch();
    return 0;
}


