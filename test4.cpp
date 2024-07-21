#include <bits/stdc++.h>
#include <string>
#include <Windows.h>
#include <cstdlib>

using namespace std;

struct Diem
{
    float diem;
    string masinhvien;
    string mamonhoc;
};

struct monhoc
{
    string tenmon;
    float tinchi;
    Diem diem;
};

struct node
{
    string tensinhvien;
    string tenlop;
    float diemtrungbinh;
    monhoc toan;
    monhoc vatly;
    monhoc tienganh;
    monhoc ctdl_gt;
    node *next;
    node *previous;
};

struct doulbelinkedList
{
    node *head;
    node *tail;
};

void init(doulbelinkedList &ls)
{
    ls.head = NULL;
    ls.tail = NULL;
}

node *createNode(string a, string b, string c1, float c2, string c3, string c4, string d1, float d2, string d3, string d4, string e1, float e2, string e3, string e4, string f1, float f2, string f3, string f4)
{
    node *p = new node;
    p->tensinhvien = a;
    p->tenlop = b;
    
    p->toan.tenmon = c1;
    p->toan.tinchi = 3;
    p->toan.diem.diem = c2;
    p->toan.diem.masinhvien = c3;
    p->toan.diem.mamonhoc = c4;
    // toan

    p->vatly.tenmon = d1;
    p->vatly.tinchi = 1;
    p->vatly.diem.diem = d2;
    p->vatly.diem.masinhvien = d3;
    p->vatly.diem.mamonhoc = d4;

    // vat ly
    p->tienganh.tenmon = e1;
    p->tienganh.tinchi = 1;
    p->tienganh.diem.diem = e2;
    p->tienganh.diem.masinhvien = e3;
    p->tienganh.diem.mamonhoc = e4;

    // tieng anh

    p->ctdl_gt.tenmon = f1;
    p->ctdl_gt.tinchi = 2;
    p->ctdl_gt.diem.diem = f2;
    p->ctdl_gt.diem.masinhvien = f3;
    p->ctdl_gt.diem.mamonhoc = f4;

    // ctdl_gt

    p->diemtrungbinh = (p->toan.diem.diem * p->toan.tinchi + p->vatly.diem.diem * p->vatly.tinchi + p->tienganh.diem.diem * p->tienganh.tinchi + p->ctdl_gt.diem.diem * p->ctdl_gt.tinchi) / (p->toan.tinchi + p->tienganh.tinchi + p->vatly.tinchi + p->ctdl_gt.tinchi);
    p->next = NULL;	
    p->previous = NULL;
    return p;
}

void addFirst(doulbelinkedList &ls, string a, string b, string c1, float c2, string c3, string c4, string d1, float d2, string d3, string d4, string e1, float e2, string e3, string e4, string f1, float f2, string f3, string f4)
{
    node *p = createNode(a, b, c1, c2, c3, c4, d1, d2, d3, d4, e1, e2, e3, e4, f1, f2, f3, f4);
    if (ls.head == NULL) // danh sach rong
    {
        ls.head = ls.tail = p;
    }
    else
    {
        p->next = ls.head;
        ls.head->previous = p;
        ls.head = p;
    }
}

// void addLast(doulbelinkedList &ls, int x, const char a[], const char b[]){
//	node *p = createNode(x, a, b);
//	if(ls.head == NULL) //danh sach rong
//	{
//		ls.head = ls.tail = p;
//	}
//	else
//	{
//		p->previous = ls.tail;
//		ls.tail->next = p;
//		ls.tail = p;
//	}

void outputLeftToRight(const doulbelinkedList ls)
{
    cout << "--------------------------------\n";
    int i = 1;
    node *p = ls.head;
    while (p != NULL)
    {
        cout << "STT: " << i << "\n";
        cout << "+Ten sinh vien: " <<  p->tensinhvien << "\n";
        cout << "+Lop: "<< p->tenlop << "\n";
        cout << "+Diem cac mon: \n";
        cout << "\t" << p->toan.tenmon << ": " << fixed << setprecision(2)<< p->toan.diem.diem << " "  <<  "\n";
        cout << "\t" << p->vatly.tenmon << ": " << fixed << setprecision(2)<< p->vatly.diem.diem << "\n";
        cout << "\t" << p->tienganh.tenmon << ": " << fixed << setprecision(2)<< p->tienganh.diem.diem << "\n";
        cout << "\t" << p->ctdl_gt.tenmon << ": " << fixed << setprecision(2)<< p->ctdl_gt.diem.diem << "\n";
        cout << "+Diem trung binh: " << fixed << setprecision(2) << p->diemtrungbinh <<"\n";
        cout << "--------------------------------";
        cout << endl;
        i++;
        p = p->next;
    }
}

// void outputRightToLeft(const doulbelinkedList ls){
//	node *p = ls.tail;
//	while (p !=NULL)
//	{
//		cout<<p->msv<<"\t"; //in msv
//		cout<<p->tensinhvien<<"\n"; //in ten sinh vien
//		p = p->previous;
//	}
// }

void nhap_linker_list(doulbelinkedList &ls)
{
    string a;
    string b;
    // toan
    string c1;
    float c2;
    string c3;
    string c4;
    // vat ly
    string d1;
    float d2;
    string d3;
    string d4;
    // ta
    string e1;
    float e2;
    string e3;
    string e4;
    // ctdl_gt
    string f1;
    float f2;
    string f3;
    string f4;
    // string test input float
    string input;
    
    while (true)
    {
        cout << "- Nhap ten sinh vien: ";
        getline(cin, a);
        if (a == "$")
        {
            break;
        }
        cout << "\t - Nhap ma sv: ";
        cin>>c3;
        if (c3 == "$")
        {
            break;
        }
        cin.ignore();
        cout << "- Nhap lop: ";
        getline(cin, b);
        if (b == "$")
        {
            break;
        }
        cout << "\t - Nhap diem toan: "; // diem mon toan
        // toan
        // tin chi = 3
            cin >> input;
            if (input == "$")
            {
                break;
            }
            c2 = stof(input);
            cout << "\t - Nhap ma mon: ";
            cin >> c4;
            if (c4 == "$")
            {
                break;
            }
        cout << "\t - Nhap diem vat ly: "; // diem mon vat ly
        // vatly
        // tin chi = 3
            cin >> input;
            if (input == "$")
            {
                break;
            }
            d2 = stof(input);
            cout << "\t - Nhap ma mon: ";
            cin >> d4;
            if (d4 == "$")
            {
                break;
            }
        cout << "\t - Nhap diem tieng anh: "; // diem mon tieng anh
        // tieng anh
        // tin chi = 3
            cin >> input;
            if (input == "$")
            {
                break;
            }
            f2 = stof(input);
            cout << "\t - Nhap ma mon: ";
            cin >> f4;
            if (f4 == "$")
            {
                break;
            }
        cout << "\t - Nhap diem ctdl_gt: "; // diem mon ctdl_gt
        // ctdl_gt
        // tin chi = 3
            cin >> input;
            if (input == "$")
            {
                break;
            }
            c2 = stof(input);
            cout << "\t - Nhap ma mon: ";
            cin >> c4;
            if (c4 == "$")
            {
                break;
            }
        system("cls");
        cin.ignore();
        addFirst(ls, a, b, c1, c2, c3, c4, d1, d2, d3, d4, e1, e2, e3, e4, f1, f2, f3, f4);
    }
}

void sortList_diemtb(doulbelinkedList &ls) //sap xep theo diem trung binh
{
    if (!ls.head || !ls.head->next)
        return; 
    
    node *sorted = NULL; 
    node *current = ls.head;

    while (current)
    {
        node *next = current->next;
        if (!sorted || sorted->diemtrungbinh >= current->diemtrungbinh)
        {
            current->next = sorted;
            if (sorted)
                sorted->previous = current;
            sorted = current;
            sorted->previous = NULL;
        }
        else
        {
            node *temp = sorted;
            while (temp->next && temp->next->diemtrungbinh < current->diemtrungbinh)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next)
                temp->next->previous = current;
            temp->next = current;
            current->previous = temp;
        }
        current = next;
    }
    ls.head = sorted;
    ls.tail = sorted;
    while (ls.tail->next)
    {
        ls.tail = ls.tail->next;
    }
}

void sortList_diemtoan(doulbelinkedList &ls) //sap xep theo diem toan
{
    if (!ls.head || !ls.head->next)
        return; 
    
    node *sorted = NULL; 
    node *current = ls.head;

    while (current)
    {
        node *next = current->next;
        if (!sorted || sorted->toan.diem.diem >= current->toan.diem.diem)
        {
            current->next = sorted;
            if (sorted)
                sorted->previous = current;
            sorted = current;
            sorted->previous = NULL;
        }
        else
        {
            node *temp = sorted;
            while (temp->next && temp->next->toan.diem.diem < current->toan.diem.diem)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next)
                temp->next->previous = current;
            temp->next = current;
            current->previous = temp;
        }
        current = next;
    }
    ls.head = sorted;
    ls.tail = sorted;
    while (ls.tail->next)
    {
        ls.tail = ls.tail->next;
    }
}

void outputsinhvien_max_min(doulbelinkedList ls){ // in sinh vien co diem max , min
    node *p = ls.tail;
    cout << "Sinh vien co diem trung binh lon nhat la: \n";
    cout << "--------------------------------\n";
    cout << "+Ten sinh vien: " <<  p->tensinhvien << "\n";
    cout << "+Lop: "<< p->tenlop << "\n";
    cout << "+Diem trung binh: " << fixed << setprecision(2) << p->diemtrungbinh <<"\n";
    cout << "--------------------------------";
    cout << endl;
    node *k = ls.head;
    cout << "Sinh vien co diem trung binh be nhat la: \n";
    cout << "--------------------------------\n";
    cout << "+Ten sinh vien: " <<  k->tensinhvien << "\n";
    cout << "+Lop: "<< k->tenlop << "\n";
    cout << "+Diem trung binh: " << fixed << setprecision(2) << k->diemtrungbinh <<"\n";
    cout << "--------------------------------";
    cout << endl;
}

void outputdiemtrungbinhmon(doulbelinkedList ls){ // tinh diem trung binh mon
    node *p = ls.head;
    string ten_mon_max;
    string ten_mon_min;
    float diemtbtoan = 0;
    float diemtbvl = 0;
    float diemtbta = 0;
    float diemtbctdl_gt = 0;
    float dem = 0;
    while (p!=NULL){
        diemtbtoan += p->toan.diem.diem;
        diemtbvl += p->vatly.diem.diem;
        diemtbta += p->tienganh.diem.diem;
        diemtbctdl_gt += p->ctdl_gt.diem.diem;
        p = p->next;
        dem++;
    }
    diemtbtoan /= dem;
    diemtbvl /= dem;
    diemtbta /= dem;
    diemtbctdl_gt /= dem;
    float min = diemtbtoan;
    ten_mon_min = "toan";
    if(min > diemtbta){
        min = diemtbta;
        ten_mon_min = "tieng anh";
    }
    if (min > diemtbctdl_gt){
        min = diemtbctdl_gt;
        ten_mon_min = "ctdl_gt";
    }
    if (min > diemtbvl){
        min = diemtbvl;
        ten_mon_min = "vat ly";
    }

    float max = diemtbtoan;
    ten_mon_max = "toan";
    if(max < diemtbta){
        max = diemtbta;
        ten_mon_max = "tieng anh";
    }
    if (max < diemtbctdl_gt){
        max = diemtbctdl_gt;
        ten_mon_max = "ctdl_gt";
    }
    if (max < diemtbvl){
        max = diemtbvl;
        ten_mon_max = "vat ly";
    }
    cout << "Mon hoc co diem trung binh cao nhat la mon " << ten_mon_max << ": " << max << endl; 
    cout << "Mon hoc co diem trung binh thap nhat la mon "<< ten_mon_min << ": "  << min;
}

int main()
{
    doulbelinkedList ls;
    doulbelinkedList lscopy;
    init(ls);	
    nhap_linker_list(ls);
    cout << "--------------------------------\n";
    cout << "Danh sach sinh vien: \n";
    outputLeftToRight(ls);
    cout << endl << endl;
    cout << "Danh sach sinh vien co diem trung binh tang dan: \n";
    sortList_diemtb(ls);
    lscopy = ls;
    outputLeftToRight(ls);
    cout << endl << endl;
    cout << "Danh sach sinh vien co diem toan tang dan: \n";
    sortList_diemtoan(ls);
    outputLeftToRight(ls);
    outputsinhvien_max_min(lscopy);
    outputdiemtrungbinhmon(ls);
    return 0;
}

