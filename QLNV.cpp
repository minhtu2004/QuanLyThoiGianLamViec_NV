#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <sstream>
#include <chrono>
using namespace std;


class Menu;
class Emp {
    friend class Menu;
    protected:
    int ID;
    string name, type;
    string pos;
    int snl = 0, snn = 0;
    int key = 0;
    string status[32];
    static int sdm;
    int wh[32];
    static int month;
    int swh = 0;
    static int ms;
    int ot[32];

    public:
    virtual ~Emp() {}
    int cf=-1;
    virtual int gethstc() const { return 0; }
    virtual int gethetc() const { return 0; }
    Emp(string h) : type(h) {}
    Emp() {}
  
    string gettt(int i) {return status[i];}
    virtual void sethstc(int hstc) { hstc = 0;}
    virtual void sethetc(int hetc) { hetc = 0;}
    void upms() {
        ms = ms + 1;
    }
    virtual void nhap() {
        cout << "Nhap ID: ";
        cin >> ID;
        cin.ignore();
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap chuc vu: ";
        getline(cin, pos);
    }

    virtual void fix() {
        cout << "Chon thong tin can chinh sua cua " << ID << endl;
        cout << "0.Sua het\n1.ID\n2.Ten\n3.Chuc vu\n" << endl;
        if(type == "PT") {
            cout << "4.Doi ca lam" << endl;
        }

        cout << "Moi nhap: ";
        cin >> cf;

        cin.ignore();

        if(cf == 1 || cf == 0) {
            cout << "Nhap ID: ";
            cin >> ID; }
        if(cf == 2 || cf == 0) {
            if(cf == 0) cin.ignore();
            cout << "Nhap ten: ";
            getline(cin, name);}
        if(cf == 3 || cf == 0) {
            cout << "Nhap chuc vu: ";
            getline(cin, pos);}       
    }

    virtual void ccv(){}
    virtual void ccr(){}
   
    virtual void settg() {
        for(int i = 0; i < 32; i++) {
            status[i] = "Chua cham cong";
            ot[i] = 0; wh[i] = 0; 
        }
    }
    
    virtual void xuat() {
        cout << setw(8) << ID << setw(15) << name 
             << setw(6) << type << setw(10) << pos;
    }
    virtual void xat(int d) {
        cout << setw(8) << ID << setw(15) << name 
             << setw(6) << type << setw(10) << pos;
    }
};

class FT: public Emp {
    private:
    int hstr[32]={}, hend[32]={};
    int mstr[32] = {}, mend[32] = {};
    int hstc=8, hetc=17;

    public:
    FT() : Emp("FT") {}
    int gethstc() const override {
        return hstc;
    }
    int gethetc() const override {
        return hetc;
    }
    void sethstc(int hs) override {
        hstc = hs;
    }
    void sethetc(int hs) override {
        hetc = hs;
    }
    void settg() override {
        for(int i = 0; i < 32; i++) {
            Emp::settg();
            hstr[i] = 0; mstr[i] = 0;
            hend[i] = 0; mend[i] = 0;
        }
    }
    void nhap() override{
        Emp::nhap(); 
        upms();  
        settg();
    }
    void ccv() override {
        int ch;
        cout << "\nChon hinh thuc cham cong\n";
        cout << "1. Nhap thu cong\n2. Lay thoi gian thuc\n";
        cout << "Moi chon: ";
        cin >> ch;
        if(ch == 2) {
        auto now = chrono::system_clock::now();
        time_t t_now = chrono::system_clock::to_time_t(now);
        tm* local = localtime(&t_now);
    
        hstr[sdm] = local->tm_hour;
        mstr[sdm] = local->tm_min;
        } else if(ch == 1) {
            cout << "Nhap gio vao: ";
            cin >> hstr[sdm];
            cout << "Nhap phut vao: ";
            cin >> mstr[sdm];
        }
    
        cout << "Nhan vien " << ID << " vao luc " 
             << setw(2) << hstr[sdm] << ":" << setw(2) << mstr[sdm] << endl;
    
        if(hstr[sdm] > hstc) {
            cout << "Nhan vien " << ID << " den tre " << hstr[sdm] - hstc << " gio " << mstr[sdm] << " phut!" << endl;
        } else {
            cout << "Nhan vien " << ID << " den dung gio!" << endl;
        } 
        status[sdm] = "Da vao lam";
    }
    void ccr() override {
        int ch;
        cout << "\nChon hinh thuc cham cong\n";
        cout << "1. Nhap thu cong\n2. Lay thoi gian thuc\n";
        cout << "Moi chon: ";
        cin >> ch;
        if(ch == 2) {
        auto now = chrono::system_clock::now();
        time_t t_now = chrono::system_clock::to_time_t(now);
        tm* local = localtime(&t_now);
    
        hend[sdm] = local->tm_hour;
        mend[sdm] = local->tm_min;
        } else if(ch == 1) {
            cout << "Nhap gio ra: ";
            cin >> hend[sdm];
            cout << "Nhap phut ra: ";
            cin >> mend[sdm];
        }
        int c = 0;
        cout << "Nhan vien " << ID << " tan lam luc " 
             << setw(2) << hend[sdm] << ":" << setw(2) << mend[sdm] << endl;
    
        if(hend[sdm] > hetc) {
            cout << "Nhan vien " << ID << " lam them " << hend[sdm] - hetc << " gio " << mend[sdm] << " phut!" << endl;
        } else if(hend[sdm] == hetc) {
            cout << "Nhan vien " << ID << " ra ve dung gio!" << endl;
        } else {
            cout << "Nhan vien " << ID << " ve som " << hetc - hend[sdm] << " gio " << mend[sdm] << " phut!" <<  endl;
        }
    
        cout << "Nhan vien " << ID << " da lam tu " 
             << setw(2) << hstr[sdm] << ":" << setw(2) << mstr[sdm]
             << " den " << setw(2) << hend[sdm] << ":" << setw(2) << mend[sdm] << endl;
    
        int total_minutes = (hend[sdm] * 60 + mend[sdm]) - (hstr[sdm] * 60 + mstr[sdm]);
        if (total_minutes < 0) total_minutes = 0;

        wh[sdm] = total_minutes / 60; 

        cout << "Tong thoi gian lam: " << total_minutes << " phut (" 
             << wh[sdm] << " gio " << total_minutes % 60 << " phut)" << endl;

        if(wh[sdm] < 0) wh[sdm] = 0;
    
        cout << "So gio da lam: " << wh[sdm] << endl;

        if(wh[sdm] < (hetc - hstc)) {
            cout << "Nhan vien " << ID << " khong lam du so gio tieu chuan!" << endl;
            cout << "Cong nhan ngay lam cua nhan vien " << ID << " hay khong?\n";
            cout << "1. Cong nhan\n2. Khong cong nhan\nMoi chon: ";
            cin >> c;
            if(c == 1) { snl++; status[sdm] = "Hoan thanh"; }
            else { snn++; status[sdm] = "Khong dat"; }
        } else {
            snl++; 
            status[sdm] = "Hoan thanh";
        }
        if(hstr[sdm] == hstc && hend[sdm] - hetc >= 1) {
            status[sdm] = "Hoan thanh co tang ca";
        }
    }
    void fix() override {
        Emp::fix(); 
    }    
    void xuat() override {
        Emp::xuat();
        cout << setw(2) << hstc << ":00 - " << setw(2) << hetc << setw(14) << ":00" 
             << setw(14) << snl << setw(14) << snn << setw(15) << swh << endl;
    }
    void xat(int d) override {
        ot[d] = hend[d] - hetc;
        if(ot[d] < 1) {ot[d]=0;}
        Emp::xat(d);
        cout << setw(2) << hstr[d] << ":" << setw(7) << mstr[d] << setw(2) << hend[d] << ":" << setw(7) 
             << mend[d] << setw(9) << wh[d] << setw(9) << ot[d]
             << setw(15) << status[d] << endl;
    }
};

class PT: public Emp {
    private:
    int hstr[32]={}, hend[32]={};
    int mstr[32] = {}, mend[32] = {};
    int hstc, hetc;
    public:
    PT() : Emp("PT") {}
    int gethstc() const override {
        return hstc;
    }
    int gethetc() const override {
        return hetc;
    }
    void sethstc(int hs) override {
        hstc = hs;
    }
    void sethetc(int hs) override {
        hetc = hs;
    }
    void settg() override {
        for(int i = 0; i < 32; i++) {
            Emp::settg();
            hstr[i] = 0; mstr[i] = 0;
            hend[i] = 0; mend[i] = 0;
        }
    }
    void nhap() override{
        Emp::nhap(); 
        int cs = 0;
        cout << "Chon ca: \n";
        cout << "1. Sang(8h-12h)\n2. Chieu(13h-17h)\n";
        cout << "Moi chon: ";
        cin >> cs;
        if(cs == 1) {hstc = 8; hetc = 12;}
        if(cs == 2) {hstc = 13; hetc = 17;}
        upms();  
        settg();
    }
    void fix() override {
        Emp::fix(); 
        int cs = 0;
        cout << "Chon ca: \n";
        cout << "1. Sang(8h-12h)\n2. Chieu(13h-17h)\n";
        cout << "Moi chon: ";
        cin >> cs;
        if(cs == 1) {hstc = 8; hetc = 12;}
        if(cs == 2) {hstc = 13; hetc = 17;}
    } 
    void ccv() override {
        int ch;
        cout << "\nChon hinh thuc cham cong\n";
        cout << "1. Nhap thu cong\n2. Lay thoi gian thuc\n";
        cout << "Moi chon: ";
        cin >> ch;
        if(ch == 2) {
        auto now = chrono::system_clock::now();
        time_t t_now = chrono::system_clock::to_time_t(now);
        tm* local = localtime(&t_now);
    
        hstr[sdm] = local->tm_hour;
        mstr[sdm] = local->tm_min;
        } else if(ch == 1) {
            cout << "Nhap gio vao: ";
            cin >> hstr[sdm];
            cout << "Nhap phut vao: ";
            cin >> mstr[sdm];
        }
    
        cout << "Nhan vien " << ID << " vao luc " 
             << setw(2) << hstr[sdm] << ":" << setw(2) << mstr[sdm] << endl;
    
        if(hstr[sdm] > hstc) {
            cout << "Nhan vien " << ID << " den tre " << hstr[sdm] - hstc << " gio " << mstr[sdm] << " phut!" << endl;
        } else {
            cout << "Nhan vien " << ID << " den dung gio!" << endl;
        } 
        status[sdm] = "Da vao lam";
    }
    void ccr() override {
        int ch;
        cout << "\nChon hinh thuc cham cong\n";
        cout << "1. Nhap thu cong\n2. Lay thoi gian thuc\n";
        cout << "Moi chon: ";
        cin >> ch;
        if(ch == 2) {
        auto now = chrono::system_clock::now();
        time_t t_now = chrono::system_clock::to_time_t(now);
        tm* local = localtime(&t_now);
    
        hend[sdm] = local->tm_hour;
        mend[sdm] = local->tm_min;
        } else if(ch == 1) {
            cout << "Nhap gio ra: ";
            cin >> hend[sdm];
            cout << "Nhap phut ra: ";
            cin >> mend[sdm];
        }
        int c = 0;
        cout << "Nhan vien " << ID << " tan lam luc " 
             << setw(2) << hend[sdm] << ":" << setw(2) << mend[sdm] << endl;
    
        if(hend[sdm] > hetc) {
            cout << "Nhan vien " << ID << " lam them " << hend[sdm] - hetc << " gio " << mend[sdm] << " phut!" << endl;
        } else if(hend[sdm] == hetc) {
            cout << "Nhan vien " << ID << " ra ve dung gio!" << endl;
        } else {
            cout << "Nhan vien " << ID << " ve som " << hetc - hend[sdm] << " gio " << mend[sdm] << " phut!" <<  endl;
        }
    
        cout << "Nhan vien " << ID << " da lam tu " 
             << setw(2) << hstr[sdm] << ":" << setw(2) << mstr[sdm]
             << " den " << setw(2) << hend[sdm] << ":" << setw(2) << mend[sdm] << endl;


        int total_minutes = (hend[sdm] * 60 + mend[sdm]) - (hstr[sdm] * 60 + mstr[sdm]);
        if (total_minutes < 0) total_minutes = 0;

        wh[sdm] = total_minutes / 60; 

        cout << "Tong thoi gian lam: " << total_minutes << " phut (" 
            << wh[sdm] << " gio " << total_minutes % 60 << " phut)" << endl;
        if(wh[sdm] < 0) wh[sdm] = 0;
    
        cout << "So gio da lam: " << wh[sdm] << endl;

        if(wh[sdm] < (hetc - hstc)) {
            cout << "Nhan vien " << ID << " khong lam du so gio tieu chuan!" << endl;
            cout << "Cong nhan ngay lam cua nhan vien " << ID << " hay khong?\n";
            cout << "1. Cong nhan\n2. Khong cong nhan\nMoi chon: ";
            cin >> c;
            if(c == 1) { snl++; status[sdm] = "Hoan thanh"; }
            else { snn++; status[sdm] = "Khong dat"; }
        } else {
            snl++; 
            status[sdm] = "Hoan thanh";
        }
        if(hstr[sdm] == hstc && hend[sdm] - hetc >= 1) {
            status[sdm] = "Hoan thanh co tang ca";
        }
    }
    
    void xuat() override {
        Emp::xuat();
        cout << setw(2) << hstc << ":00 - " << setw(2) << hetc << setw(14) << ":00" 
             << setw(14) << snl << setw(14) << snn << setw(15) << swh << endl;
    }
    void xat(int d) override {
        ot[d] = hend[d] - hetc;
        if(ot[d] < 1) {ot[d]=0;}
        Emp::xat(d);
        cout << setw(2) << hstr[d] << ":" << setw(7) << mstr[d] << setw(2) << hend[d] << ":" << setw(7) 
             << mend[d] << setw(9) << wh[d] << setw(9) << ot[d]
             << setw(15) << status[d] << endl;
    }
};


int Emp::sdm = 1;
int Emp::month = 1;
int Emp::ms = 0;

class Menu {
    private:
    int n;
    vector<Emp*> le;
    string adm = "admin";
    string pw = "qlvn";

    public:
    void va() {
        string us, mk;
        bool login = false; 
        cout << "\n=== HE THONG QUAN LY NHAN VIEN ===\n";
        
        while (!login) {
            cout << "Tai khoan: ";
            getline(cin, us);
            cout << "Mat khau: ";
            getline(cin, mk);

            if (us == adm && mk == pw) {
                cout << "\nDang nhap thanh cong!\n";
                cout << "Xin chao Admin!\n";
                login = true; 
            } else {
                cout << "\n>> Sai tai khoan hoac mat khau! Vui long nhap lai.\n\n";
            }
        }
    }
    
    void capnhatngay() {
        string u;
        cout << "Hom nay ngay thu " << Emp::sdm << " trong thang!" << endl;
        cout << "Khi cap nhap ngay, cac nhan vien chua cham cong se tinh la nghi!" << endl;
        // cin.ignore();
        cout << "Cap nhap(Y/N): ";
        getline(cin, u);
        
        if(u == "Y") {
            for (Emp* nv : le) {
                if(nv->key == 1 && nv->status[Emp::sdm] == "Da vao lam") {
                    nv->status[Emp::sdm] = "Quen cham cong ra";
                    nv->wh[Emp::sdm] = 0; 
                }
                else if(nv->key == 0) {
                    nv->snn++;
                    nv->status[Emp::sdm] = "Nghi khong phep";
                }

                nv->swh = nv->swh + nv->wh[Emp::sdm];
                nv->key = 0;
            }
            
            if(Emp::sdm == 31) {Emp::sdm = 1; Emp::month++;}
            else {Emp::sdm++;}
            if(Emp::month == 13) {Emp::month=1;}
            cout << "Da cap nhat ngay moi!\n";
        }
    }

    void chamcong() {
        int id, t = 0, c, sl;
        string reason;
        cout <<"Nhap ID nhan vien: ";
        cin >> id;
        
        auto it = std::find_if(le.begin(), le.end(), [id](Emp* emp) { return emp->ID == id; });
        
        if (it != le.end()) {
            cout << "Chon loai cham cong: \n";
            if ((*it)->key == 2) {
                cout << "Nhan vien nay da xin nghi phep!\n";
            } else if ((*it)->key == 0) {
                cout << "1. Vao lam\n";
                cout << "3. Xin nghi\n";
            } else if ((*it)->key == 1) {
                cout << "2. Tan lam\n";
            }
            cout << "Nhan 0 de thoat\n";
            cout << "Moi chon: ";
            cin >> c;            
            cin.ignore();    

            if (c == 1 && (*it)->key == 0) {
                (*it)->ccv(); 
                (*it)->key = 1;
            }
            if (c == 2 && (*it)->key == 1) {
                (*it)->ccr();
            }
            if (c == 3 && (*it)->key == 0) {
                (*it)->status[Emp::sdm] = "Xin nghi phep";
                cout << "Nhap li do nghi: ";
                getline(cin, reason);
            }
            if ((*it)->status[Emp::sdm] == "Xin nghi phep") {
                cout << "Nhan vien " << (*it)->ID << " muon xin nghi hom nay!\n";
                cout << "Li do: " << reason << endl;
                if((*it)->snn >= 4) {
                    cout << "Canh bao: Da nghi " << (*it)->snn << "/4 ngay!\n";
                }
                cout << "1. Chap nhan\n2. Khong chap nhan\n";
                cout << "Moi chon: ";
                cin >> sl;
                if (sl == 1) {                    
                    (*it)->snn++; 
                    (*it)->key = 2;
                } else {
                    (*it)->status[Emp::sdm] = "Chua cham cong";
                }
            }
            t++;
        }
        if(t == 0) { cout << "\nKhong tim thay ID nay!\n"; } 
    }

    void xoa() {
        int id;
        int c;
        cout << "Xoa:" << endl;
        cout << "1. Xoa 1 nhan vien" << endl;
        cout << "2. Xoa tat ca" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> c;
    
        if (c == 1) {
            cout << "Nhap ID nhan vien can xoa: ";
            cin >> id;
            for (auto it = le.begin(); it != le.end(); ) { 
                if ((*it)->ID == id) {
                    delete *it;
                    it = le.erase(it); 
                    cout << "Da xoa nhan vien co ID: " << id << endl;
                    return; // Xóa xong thoát luôn
                } else {
                    ++it;
                }
            }
            cout << "Khong tim thay nhan vien co ID: " << id << endl;
        } 
        else if (c == 2) {
            for (Emp* sv : le) {
                delete sv;
            }
            le.clear();
            cout << "Da xoa tat ca nhan vien." << endl;
            Emp::ms = 0; 
        }
    }

    void fixnv() {
        int id, t = 0;
        cout <<"Nhap ID nhan vien can chinh sua: ";
        cin >> id;
        auto it = std::find_if(le.begin(), le.end(), [id](Emp* emp) { return emp->ID == id; });
        if (it != le.end()) {
            (*it)->fix(); 
            t++;
        }
        if(t == 0) { cout << "\nKhong tim thay!\n"; } 
    }

    void ghicsv() {
        ofstream file("output.csv"); 
        if (file.is_open()) {
            file << "ID,Ten,Loai,Chuc vu,Gio vao quy dinh,Gio ra quy dinh,So ngay lam,So ngay nghi,Tong gio lam\n";
            for (int i = 0; i < le.size(); i++) {
                file << le[i]->ID << "," 
                     << le[i]->name << "," 
                     << le[i]->type << ","
                     << le[i]->pos << ","
                     << le[i]->gethstc() << "," 
                     << le[i]->gethetc() << "," 
                     << le[i]->snl << ","
                     << le[i]->snn << ","
                     << le[i]->swh << "\n";
            }
            file.close();
            cout << "Ghi file CSV thanh cong!\n";
        } else {
            cout << "Khong the mo file de ghi!\n";
        }
    }

    void doccsv() {
        if(le.size() > 0) { 
            Emp::ms = le.back()->ID;
        }

        ifstream file("input.csv"); 
        if (file.is_open()) {
            string line;
            getline(file, line); 
        
            while (getline(file, line)) { 
                stringstream ss(line);
                string temp;
                int hs, hen, id;
                Emp* s = nullptr;
                
                // Đọc ID
                getline(ss, temp, ','); 
                if(temp.empty()) continue; 
                id = stoi(temp);

                getline(ss, temp, ','); string ten = temp;
                getline(ss, temp, ','); string he = temp;
                getline(ss, temp, ','); string chucvu = temp;

                if (he == "FT") s = new FT();
                else if (he == "PT") s = new PT();
                else s = new Emp();
                
                s->ID = id; 
                if(id > Emp::ms) Emp::ms = id; 

                s->name = ten;
                s->type = he;
                s->pos = chucvu;

                getline(ss, temp, ','); hs = stoi(temp); s->sethstc(hs);
                getline(ss, temp, ','); hen = stoi(temp); s->sethetc(hen);
                getline(ss, temp, ','); s->snl = stoi(temp);
                getline(ss, temp, ','); s->snn = stoi(temp);
                getline(ss, temp, ','); s->swh = stoi(temp);     
                
                s->settg(); 
                le.push_back(s);
            }
            file.close();
            cout << "Doc file CSV thanh cong!\n";
        } else {
            cout << "Khong tim thay file data.csv!\n";
        }
    }
    void them() {
        int m;
        n = le.size();
        string he;
        Emp* nv = nullptr;
        cout << "Nhap so luong nhan vien: ";
        cin >> m;
        cin.ignore();

        for(int i = n; i < m+n; i++) {
            cout << "\nNhap nhan vien thu " << i + 1 << endl;
            cout << "Nhap he: ";
            getline(cin, he);
            if (he == "FT") {
                nv = new FT();
            } else if (he == "PT") {
                nv = new PT();
            } else {
                cout << "He khong hop le!\n";
                i--;
                continue;
            }
            nv->nhap();
            le.push_back(nv);
        }
        n = m + n;
    }
    void xuats(vector<Emp*> &le) {
        cout << "Bang thong ke ngay lam viec nhan vien\n";
        cout << "Hom nay ngay thu " << Emp::sdm << "/30 ngay trong thang " << Emp::month << "!" << endl;
        cout << left << setw(8) << "ID" << setw(15) << "Ten" << setw(6) << "Loai" << setw(10) << "Chuc vu"
             << setw(23) << "Thoi gian tieu chuan" << setw(14) << "So ngay lam" << setw(14) << "So ngay nghi" 
             << setw(15) << "So gio lam trong thang"  << endl;
        cout << string(120, '-') << endl;
        for (Emp* sv : le) {
            sv->xuat();
        }
    }
    void xa(vector<Emp*> &le) {
        int d;
        cout << "Chon ngay trong thang(1-" << Emp::sdm << "): ";
        cin >> d;
        cout << "Bang thong ke theo ngay\n";
        cout << "Ngay thu " << d << "/30 ngay trong thang " << Emp::month << "!" << endl;
        cout << left << setw(8) << "ID" << setw(15) << "Ten" << setw(6) << "Loai" << setw(10) << "Chuc vu"
             << setw(9) << "Gio vao" << setw(9) << "Gio ra" << setw(9) << "So gio" << setw(9) << "Tang ca" 
             << setw(15) << "Ghi chu"  << endl;
        cout << string(120, '-') << endl;
        for (Emp* sv : le) {
            sv->xat(d);
        }
    }
void mnc() {
        int c = -1;
        // va(); 
        while(c != 0) {
            cout << "\n" << string(5, '=') << " Menu " << string(5, '=') << endl;
            cout << "Hom nay ngay thu " << Emp::sdm << "/30 - Thang " << Emp::month << endl; 
            cout << "1. Xuat bang thong ke thang" << endl;
            cout << "2. Cham cong nhan vien" << endl;
            cout << "3. Cap nhat ngay moi" << endl;
            cout << "4. Xoa nhan vien" << endl;
            cout << "5. Chinh sua thong tin" << endl;
            cout << "6. Them nhan vien" << endl;
            cout << "7. Doc csv" << endl;
            cout << "8. Ghi csv" << endl;
            cout << "9. Xuat bang thong ke ngay" << endl;
            cout << "0. Thoat" << endl;
            cout << "Nhap lua chon: ";
            cin >> c;
            
            if(c == 1) {xuats(le);}
            if(c == 2) {chamcong();}   
            if(c == 3) {capnhatngay();} 
            if(c == 4) {xoa();}        
            if(c == 5) {fixnv();}      
            if(c == 6) {them();}
            if(c == 7) {doccsv();}     
            if(c == 8) {ghicsv();}     
            if(c == 9) {xa(le);}
        }
    }
    ~Menu() {
        for (Emp* nv : le) delete nv;
    }    
};
int main() {
    Menu m;
    m.mnc();
    return 0;
}