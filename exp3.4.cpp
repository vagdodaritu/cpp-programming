#include<iostream>
#include<string>
using namespace std;


template<class T>
void display(T arr[],int n){
for(int i=0;i<n;i++){
cout<<arr[i]<<" ";}
cout<<endl;}

template<class T >
T findmax(T arr[],int n){
T max=arr[0];
for(int i=1;i<n;i++){
if(max<arr[i]){
max=arr[i];}
}
return max;}
template<class T>
void reverse(T arr[],int n){
for(int i=0;i<n/2;i++){
T temp=arr[i];
arr[i]=arr[n-1-i];
arr[n-1-i]=temp;}}

 template<class T>

void leader(T arr[],int n){
T max=arr[n-1];
for(int i=n-2;i>=0;i--){
if(arr[i]>max){
max=arr[i];
cout<<max<<" ";}}
cout<<endl;}


int main(){
int n;
cout<<"enter num";
cin>>n;
 int arr1[100];
    cout << " integer array:";
    for(int i = 0; i < n; i++)
        cin >> arr1[i];

    display(arr1, n);
    cout << "max: " << findmax(arr1, n) << endl;
    reverse(arr1, n);
    cout << "reversed: ";
    display(arr1, n);
    leader(arr1, n);


    float arr2[100];
    cout << "enter float array:";
    for(int i = 0; i < n; i++)
        cin >> arr2[i];

    display(arr2, n);
    cout << "max: " << findmax(arr2, n) << endl;
    reverse(arr2, n);
    cout << "reversed:" ;
    display(arr2, n);
    leader(arr2, n);


    char arr3[100];
    cout << "enter character array:";
    for(int i = 0; i < n; i++)
        cin >> arr3[i];

    display(arr3, n);
    cout << "max : " << findmax(arr3, n) << endl;
    reverse(arr3, n);
    cout << "Reversed: ";
    display(arr3, n);
    leader(arr3, n);

    return 0;
}
