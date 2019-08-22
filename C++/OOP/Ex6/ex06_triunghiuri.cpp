#include <iostream>
#include <vector>

using namespace std;



// vector<vector<int>> generate(int numRows) {
//     vector<vector<int>> triangle;
//     vector<int> values;

//     for(int i = 0; i < numRows; i++){
//         for(int j = 0; j <= i; j++){
//             int v = rand();
//             values.push_back(v);
//         }
//     }
//     for(int i = 0; i < numRows; i++){
//         for(int j = 0; j <= i; j++){
//             int v = rand();
//             triangle.push_back(values);
//         }
//     }
//     return triangle;
// }

vector<vector<int>> generate(int n){
    vector<vector<int>> v;
    for(int i=0; i<=n; i++){
        vector<int> vv(i, i);
        v.push_back(vv);
    }
    return v;
}

void generate_vector(int cols, vector<int> &v){

    for(int i=0; i< cols; i++){
        v.push_back(i);
    }
}

void generate_triangle(int rows, vector<vector<int>> &v){
    for(int i=0; i < rows; i++){
        vector<int> row;
        generate_vector(i, row);
        v.push_back(row);
    }


}

void display(vector<vector<int>> &mat){
   for(auto line : mat){
        for(auto e : line)
            cout << e << " ";
        cout << endl;
   }
}

void add(vector<vector<int>> &t1, vector<vector<int>> &t2, vector<vector<int>> &r){

    for(int i=0 ;i < t1.size(); i++){
        r.push_back(vector<int>(i+1));
        for(int j=0; j< t1[i].size(); j++){
            r[i][j] = t1[i][j] + t2[i][j];
        }
    }
}

void add2(vector<vector<int>> &t1, vector<vector<int>> &t2, vector<vector<int>> &r){
    for( int i=0; i < t1.size(); i++ ){
        r.push_back(vector<int>(i+1));
        auto &v1 {t1[i]};
        auto &v2 {t2[i]};
        auto &result {r[i]};

        for(int j=0; i < v1.size(); j++){
            result[j] = v1[j] + v2[j];
        }
    }
}

int main(){

    auto v {generate(10)};
    display(v);

    vector<vector<int>> triangle1;
    generate_triangle(5, triangle1);
    display(triangle1);

    vector<vector<int>> triangle2;
    generate_triangle(5, triangle2);
    display(triangle2);

    vector<vector<int>> result;
    add(triangle1, triangle2, result);
    display(result);
    return 0;
}