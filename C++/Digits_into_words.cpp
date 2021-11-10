// Converting digits into words
void print_indianSystem(string [],string [],int,int);
void print_internationalSystem(string [],string [],int,int);
int main() {
	int n, rem, a = 0, count = 0,choice;
	cout << "Enter number\n";
	cin >> n;
	string strones[] = { " ","one" , "two","three","four","five","six","seven","eight","nine" };
	string strtens[] = { " ","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
	while (n != 0) {
		rem = n % 10;
		count = count + 1;
		a = a * 10 + rem;
		n = n / 10;
	}
	cout << "Enter 1 for printing words in number system\nEnter 2 for printing words in international system\n";
	cin >> choice;
	switch (choice) {
	case 1:
		print_indianSystem(strones,strtens,a,count);
		break;
	case 2:
		print_internationalSystem(strones,strtens,a,count);
		break;
	default:
		cout << "Invalid Input\n";
	}
	return 0;
}
// Indian numeral system
void print_indianSystem(string strones [] ,string strtens [], int a,int count) {
	int rem;
	if (a == 0) {
		cout << "zero";
	}
	else if ((count > 1) && ((a > 0) && (a <= 9))) {
		rem = a % 10;
		if (count == 5) {
			cout << strtens[rem] << " thousand ";
		}
		if (count == 6) {
			cout << strones[rem] << " lakh ";
		}
		if (count == 7) {
			cout << strtens[rem] << " lakh ";
		}
		if (count == 8) {
			cout << strones[rem] << " crore ";
		}
	}
	else {
		while (a != 0) {
			rem = a % 10;
			if (count == 8) {
				cout << strones[rem] << " crore ";
			}
			if (count == 7) {
				cout << strtens[rem] << " ";
			}
			if (count == 6) {
				cout << strones[rem] << " lakh ";
			}
			if (count == 5) {
				cout << strtens[rem] << " ";
			}
			if (count == 4) {
				cout << strones[rem] << " thousand ";
			}
			if (count == 3) {
				cout << strones[rem] << " hundred ";
			}
			if (count == 2) {
				cout << strtens[rem]<<" ";
			}
			if (count == 1) {
				cout << strones[rem]<<" ";
			}
			a = a / 10;
			count = count - 1;
		}
	}
}
//international numeral system
void print_internationalSystem(string strones[], string strtens[], int a,int count) {
	int rem;
	if (a == 0) {
		cout << "zero";
	}
	else if ((count > 1) && ((a > 0) && (a <= 9))) {
		rem = a % 10;
		if (count == 5) {
			cout << strtens[rem] << " thousand ";
		}
		if (count == 6) {
			cout << strones[rem] << " hundred thousand ";
		}
		if (count == 7) {
			cout << strones[rem] << " million ";
		}
		if (count == 8) {
			cout << strtens[rem] << " million ";
		}
	}
	else {
		while (a != 0) {
			rem = a % 10;
			if (count == 8) {
				cout << strtens[rem] << " ";
			}
			if (count == 7) {
				cout << strones[rem] << " million ";
			}
			if (count == 6) {
				cout << strones[rem] << " hundred ";
			}
			if (count == 5) {
				cout << strtens[rem] << " ";
			}
			if (count == 4) {
				cout << strones[rem] << " thousand ";
			}
			if (count == 3) {
				cout << strones[rem] << " hundred ";
			}
			if (count == 2) {
				cout << strtens[rem] << " ";
			}
			if (count == 1) {
				cout << strones[rem] << " ";
			}
			a = a / 10;
			count = count - 1;
		}
	}
}
