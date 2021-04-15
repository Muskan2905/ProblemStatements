// Transforming statements when there is more than one empty string 
void transform_statement(string [] , int);
int n;
int main() {
	string str[] = { "This is a text" , " " , "This is a text" , " "," ", " " ,  " " ,  "This is a text" , " " , "This is a text" , " " , "This is a text" , " "," ", "This is a text"," " , "This is a text" , "This is a text" , "This is a text" };
	n = sizeof(str) / sizeof(str[0]);
	for (int i = 0; i < n; i++) {
		cout << str[i] << endl;
	}
	cout << "\nStatements transformed when they encounters more than one space\n"<<endl;
	transform_statement(str , n);
	return 0;
}

void transform_statement(string str[] , int n) {
	int i,j=0,k;
	for (i = 0; i < n; i++) {
			j = i + 1;
			if ((j != i) && ((str[j] == " ")&&( str[i] == " "))) {
				for (k = i; k < n-1; k++) {
					str[k] = str[j];
					j = j + 1;
				}
				n = n - 1;
				i = i - 1;
			}
	}
	for (i = 0; i < n; i++) {
		cout << str[i] << endl;
	}
}
