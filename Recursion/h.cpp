#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Node
{
    friend class LinkedList;
private:
    Node* Left;
    Node* Right;
    Node* Up;
    Node* Down;
public:
    Node()
    {
        Left = NULL;
        Right = NULL;
        Up = NULL;
        Down = NULL;
    }
};

class LinkedList
{

    Node* node1, * node2, * node3, * node4, * node5, * node6;
public:
    int Time[4];

    LinkedList()
    {
        this->node1 = new Node();
        this->node2 = new Node();
        this->node3 = new Node();
        this->node4 = new Node();
        this->node5 = new Node();
        this->node6 = new Node();
    }
    LinkedList(int num)
    {
        this->node1 = new Node();
        this->node2 = new Node();
        this->node3 = new Node();
        this->node4 = new Node();
        this->node5 = new Node();
        this->node6 = new Node();

        Patterns_List(num);
    }


    void Patterns_List(int k)
    {
        if (k == 0)
        {
            node1->Right = node2;
            node2->Left = node1;
            node2->Down = node4;
            node4->Up = node2;
            node4->Down = node6;
            node6->Up = node4;
            node6->Left = node5;
            node5->Right = node6;
            node5->Up = node3;
            node3->Down = node5;
            node3->Up = node1;
            node1->Down = node3;

        }
        if (k == 1)
        {
            node1->Down = node3;
            node3->Up = node1;
            node3->Down = node5;
            node5->Up = node3;
        }
        if (k == 2)
        {
            node1->Right = node2;
            node2->Left = node1;
            node2->Down = node4;
            node4->Up = node2;
            node4->Left = node3;
            node3->Right = node4;
            node3->Down = node5;
            node5->Up = node3;
            node5->Right = node6;
            node6->Left = node5;
        }
        if (k == 3)
        {
            node1->Right = node2;
            node2->Left = node1;
            node2->Down = node4;
            node4->Up = node2;
            node4->Left = node3;
            node3->Right = node4;
            node4->Down = node6;
            node6->Up = node4;
            node6->Left = node5;
            node5->Right = node6;

        }
        if (k == 4)
        {
            node1->Down = node3;
            node3->Up = node1;
            node3->Right = node4;
            node4->Left = node3;
            node4->Up = node2;
            node2->Down = node4;
            node4->Down = node6;
            node6->Up = node4;

        }
        if (k == 5)
        {
            node2->Left = node1;
            node1->Right = node2;
            node1->Down = node3;
            node3->Up = node1;
            node3->Right = node4;
            node4->Left = node3;
            node4->Down = node6;
            node6->Up = node4;
            node6->Left = node5;
            node5->Right = node6;
        }
        if (k == 6)
        {
            node1->Right = node2;
            node2->Left = node1;
            node1->Down = node3;
            node3->Up = node1;
            node3->Right = node4;
            node4->Left = node3;
            node3->Down = node5;
            node5->Up = node3;
            node5->Right = node6;
            node6->Left = node5;
            node6->Up = node4;
            node4->Down = node6;
        }
        if (k == 7)
        {
            node1->Right = node2;
            node2->Left = node1;
            node2->Down = node4;
            node4->Up = node2;
            node4->Down = node6;
            node6->Up = node4;
        }
        if (k == 8)
        {
            node1->Right = node2;
            node2->Left = node1;
            node2->Down = node4;
            node4->Up = node2;
            node4->Down = node6;
            node6->Up = node4;
            node4->Left = node3;
            node3->Right = node4;
            node6->Left = node5;
            node5->Right = node6;
            node5->Up = node3;
            node3->Down = node5;
            node3->Up = node1;
            node1->Down = node3;
        }
        if (k == 9)
        {
            node1->Right = node2;
            node2->Left = node1;
            node2->Down = node4;
            node4->Up = node2;
            node4->Down = node6;
            node6->Up = node4;
            node4->Left = node3;
            node3->Right = node4;

        }
    }

    void set_Cursor_Position(int newX, int newY)
    {
        COORD Pos;
        Pos.X = newX;
        Pos.Y = newY;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
    }


    void Display(int col1, int col2)
    {
        int row1 = 5, row2 = 9, row3 = 14;

        if (node1->Right != NULL)
        {
            set_Cursor_Position(col1, row1);
            cout << "****";
        }
        if (node1->Down != NULL)
        {
            set_Cursor_Position(col1, row1 + 1);
            cout << "*";
            set_Cursor_Position(col1, row1 + 2);
            cout << "*";
            set_Cursor_Position(col1, row1 + 3);
            cout << "*";
            set_Cursor_Position(col1, row1 + 4);
            cout << "*";

        }

        if (node2->Left != NULL)
        {
            set_Cursor_Position(col1, row1);
            cout << "****";
        }
        if (node2->Down != NULL)
        {
            set_Cursor_Position(col2, row1 + 1);
            cout << "*";
            set_Cursor_Position(col2, row1 + 2);
            cout << "*";
            set_Cursor_Position(col2, row1 + 3);
            cout << "*";
            set_Cursor_Position(col2, row1 + 4);
            cout << "*";
        }

        if (node3->Up != NULL)
        {
            set_Cursor_Position(col1, row1 + 1);
            cout << "*";
            set_Cursor_Position(col1, row1 + 2);
            cout << "*";
            set_Cursor_Position(col1, row1 + 3);
            cout << "*";
            set_Cursor_Position(col1, row1 + 4);
            cout << "*";
        }
        if (node3->Right != NULL)
        {
            set_Cursor_Position(col1, row2);
            cout << "****";
        }
        if (node3->Down != NULL)
        {
            set_Cursor_Position(col1, row2 + 1);
            cout << "*";
            set_Cursor_Position(col1, row2 + 2);
            cout << "*";
            set_Cursor_Position(col1, row2 + 3);
            cout << "*";
            set_Cursor_Position(col1, row2 + 4);
            cout << "*";
        }

        if (node4->Left != NULL)
        {
            set_Cursor_Position(col1, row2);
            cout << "****";
        }
        if (node4->Up != NULL)
        {
            set_Cursor_Position(col2, row1 + 1);
            cout << "*";
            set_Cursor_Position(col2, row1 + 2);
            cout << "*";
            set_Cursor_Position(col2, row1 + 3);
            cout << "*";
            set_Cursor_Position(col2, row1 + 4);
            cout << "*";
        }
        if (node4->Down != NULL)
        {
            set_Cursor_Position(col2, row2 + 1);
            cout << "*";
            set_Cursor_Position(col2, row2 + 2);
            cout << "*";
            set_Cursor_Position(col2, row2 + 3);
            cout << "*";
            set_Cursor_Position(col2, row2 + 4);
            cout << "*";
        }
        if (node5->Up != NULL)
        {
            set_Cursor_Position(col1, row2 + 1);
            cout << "*";
            set_Cursor_Position(col1, row2 + 2);
            cout << "*";
            set_Cursor_Position(col1, row2 + 3);
            cout << "*";
            set_Cursor_Position(col1, row2 + 4);
            cout << "*";
        }

        if (node5->Right != NULL)
        {
            set_Cursor_Position(col1, row3);
            cout << "****";
        }
        if (node6->Left != NULL)
        {
            set_Cursor_Position(col1, row3);
            cout << "****";
        }

        if (node6->Up != NULL)
        {
            set_Cursor_Position(col2, row2 + 1);
            cout << "*";
            set_Cursor_Position(col2, row2 + 2);
            cout << "*";
            set_Cursor_Position(col2, row2 + 3);
            cout << "*";
            set_Cursor_Position(col2, row2 + 4);
            cout << "*";
        }


    }


    void AdditionHours()
    {
        int AddHours;
        cout << "Enter hours to add in the current Time: ";
        cin >> AddHours;

        int TotalHours = (Time[0] * 10 + Time[1] + AddHours) % 24;
        Time[0] = TotalHours / 10;
        Time[1] = TotalHours % 10;
  

    }

    void SubtractHours()
    {
        int SubtractHour;
        cout << "Enter hours to subtract from the current Time: ";
        cin >> SubtractHour;

        int TotalHours = (Time[0] * 10 + Time[1] - SubtractHour + 24) % 24;
        Time[0] = TotalHours / 10;
        Time[1] = TotalHours % 10;
    }

    void SubtractMinutes()
    {
        int SubtractMin;
        cout << "Enter minutes to subtract: ";
        cin >> SubtractMin;

        int TotalMin = (Time[2] * 10 + Time[3]) - SubtractMin;

        while (TotalMin < 0)
        {
            TotalMin += 60;
            if (Time[1] > 0)
            {
                Time[1]--; 
            }
            else if (Time[0] > 0)
            {
                Time[0]--;
                Time[1] = 9; 
            }
            else
            {
                
                Time[0] = 2;
                Time[1] = 3;
            }
        }

        Time[2] = TotalMin / 10;
        Time[3] = TotalMin % 10;
    }

    void AdditionMinutes()
    {
        int AddMin;
        cout << "Enter minutes to add: ";
        cin >> AddMin;

        int TotalMin = ((Time[2] * 10) + Time[3] + AddMin) % 60;
        int AdditionalHours = ((Time[2] * 10) + Time[3] + AddMin) / 60;

        int TotalHours = (Time[0] * 10 + Time[1] + AdditionalHours) % 24;
        Time[0] = TotalHours / 10;
        Time[1] = TotalHours % 10;
        Time[2] = TotalMin / 10;
        Time[3] = TotalMin % 10;

    }

};

int main()
{
    LinkedList Obj;
    int Time;

    cout << "Enter the initial Time (in HHMM format): ";
    cin >> Time;

    int Minutes = Time % 100;
    int Hours = Time / 100;

    Obj.Time[0] = Hours / 10;
    Obj.Time[1] = Hours % 10;
    Obj.Time[2] = Minutes / 10;
    Obj.Time[3] = Minutes % 10;

    while (true)
    {
        system("CLS");
        LinkedList Obj1(Obj.Time[0]);
        LinkedList Obj2(Obj.Time[1]);
        LinkedList Obj3(Obj.Time[2]);
        LinkedList Obj4(Obj.Time[3]);

        Obj1.Display(5, 10);
        Obj2.Display(15, 20);
        Obj3.Display(25, 30);
        Obj4.Display(35, 40);
        cout << endl << endl << endl;

        int Choice;
        cout << "Enter 1 for Addition in Hours " << endl;
        cout << "Enter 2 for Subtraction in Hours " << endl;
        cout << "Enter 3 for Addition in minutes " << endl;
        cout << "Enter 4 for Subtraction in minutes " << endl;
        cout << "Enter 5 to exit " << endl;
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            Obj.AdditionHours();
            break;
        case 2:
            Obj.SubtractHours();
            break;
        case 3:
            Obj.AdditionMinutes();
            break;
        case 4:
            Obj.SubtractMinutes();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << " Invalid Choice " << endl;
        }
    }

    return 0;
}