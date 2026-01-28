#include <iostream>
using namespace std;

int matrixaddition(int** matrix1, int** matrix2, int** result, int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }
    cout<<"resultant matrix after addition is:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

int matrixsubraction(int** matrix1, int** matrix2, int** result, int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result[i][j]=matrix1[i][j]-matrix2[i][j];
        }
    }
    cout<<"resultant matrix after subtraction is:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

int matrixmultiplication(int** matrix1, int** matrix2, int** result, int rows1, int cols1, int rows2, int cols2){
    if(cols1!=rows2){
        cout<<"Incompatible matrix dimensions"<<endl;
        return -1;
    }
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols2;j++){
            result[i][j]=0;
            for(int k=0;k<cols1;k++){
                result[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    cout<<"resultant matrix after multiplication is:"<<endl;
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols2;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

int main(){
    int rows, cols;
    cout<<"enter number of rows for matrices: ";
    cin>>rows;
    cout<<"enter number of columns for matrices: ";
    cin>>cols;
    
    int** matrix1 = new int*[rows];
    int** matrix2 = new int*[rows];
    int** result = new int*[rows];
    
    for(int i=0;i<rows;i++){
        matrix1[i] = new int[cols];
        matrix2[i] = new int[cols];
        result[i] = new int[cols];
    }
    
    cout<<"enter elements of matrix1:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>matrix1[i][j];
        }
    }
    cout<<"enter elements of matrix2:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>matrix2[i][j];
        }
    }
    cout<<"matrix1 is:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<matrix1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"matrix2 is:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<matrix2[i][j]<<" ";
        }
        cout<<endl;
    }
    int choice;
    cout<<"enter 1 for addition, 2 for subtraction, 3 for multiplication: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        matrixaddition(matrix1,matrix2,result,rows,cols);
        break;
    case 2:
        matrixsubraction(matrix1,matrix2,result,rows,cols);
        break;
    case 3:
        matrixmultiplication(matrix1,matrix2,result,rows,cols,rows,cols);
        break;
    
    default:
        cout<<"invalid choice"<<endl;
        break;
    }
    
    
    for(int i=0;i<rows;i++){
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] result[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] result;
    
    return 0;
}