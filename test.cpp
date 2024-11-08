#include<bits/stdc++.h>
using namespace std;

class SymbolInfo{
private:
    string name="", type="";
public:
    SymbolInfo(string name, string type){
        this->name = name;
        this->type = type;
    }
    string getName(){
        return this->name;
    }
    string getType(){
        return this->type;
    }
};
class SymbolTable{
private:
    vector<SymbolInfo>ans[5];
    int hashsz=5;
public:
    SymbolTable(){}
    void Insert(SymbolInfo obj){
        string s=obj.getName();
        int indx=hashFunc(s);
        ans[indx].push_back(obj);
        cout<<"Inserted at position "<<indx<<" , "<<ans[indx].size()-1<<endl;
    }
    int hashFunc(string x){
        int sz = x.size();
        int mod = sz % hashsz;
        return mod;
    }
    void Lookup(string x){
        int sz = x.size(), j=0;
        int mod = hashFunc(x);
        for(vector<SymbolInfo>::iterator it = ans[mod].begin(); it != ans[mod].end(); it++){
            if(it->getName() == x){
                cout<<x<<" found at "<<mod<<" , "<<j<<endl;
                break;
            }
            j++;
        }
    }
    void Delete(string x){
        int sz = x.size(), j=0;
        int mod = hashFunc(x);
        for(vector<SymbolInfo>::iterator it = ans[mod].begin(); it != ans[mod].end(); it++){
            if(it->getName() == x){
                ans[mod].erase(ans[mod].begin()+j,ans[mod].begin()+j+1);
                cout<<"Deleted from "<<mod<<" , "<<j<<endl;
                break;
            }
            j++;
        }
    }
    void print(){
        for(int i=0;i<5;i++){
            if(ans[i].size() != 0){
                cout<<i<<" ==> ";
                for(vector<SymbolInfo>::iterator it=ans[i].begin(); it != ans[i].end(); it++){
                    cout<< "<" <<it->getName()<<" "<<it->getType()<< "> ";
                }
                cout<<endl;
            }
        }
    }
};
int main(){
    int tc=8;
    SymbolTable st;
    while(tc--){
        string a,b,c;
        cin>>a;
        if(a == "I"){
            cin>>b>>c;
            SymbolInfo obj(b,c);
            st.Insert(obj);
        }
        else if(a == "P"){
            st.print();
        }
        else if(a == "L"){
            cin>>b;
            st.Lookup(b);
        }
        else if(a == "D"){
            cin>>b;
            st.Delete(b);
        }
    }

    return 0;
}
