#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
int at[10], bt[10], tat[10], ft[10], ftnew[10], wt[10], n, i, j, k, process[10][2], quantum;
int counterflag = 0, complete = 0, countt = 0;
string pidholder[10];
string pid[10];
void swapp(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swapp(string* a, string* b) {
	string temp = *a;
	*a = *b;
	*b = temp;
}
void bubble(int arrayy[10][2], int nvar) { //sorts ats
	for (i = 0; i < nvar - 1; i++) {
		for (j = 0; j < nvar - i - 1; j++) {
			if (arrayy[j][0] >= arrayy[j + 1][0]) {
				k = 0;
				swapp(&pid[j], &pid[j + 1]);//sort pids
				swapp(&at[j], &at[j + 1]);
				swapp(&bt[j], &bt[j + 1]);
				while (k < 2) {
					swapp(&arrayy[j][k], &arrayy[j + 1][k]); //sort bt along with at
					k++;
				}
			}
		}
	}
}
void execute(int arrayy[10][2], int end) {//pass process 
	for (int y = 0; y < n; y++) {
		if (process[y][1] == 0) {//finished processes
			if (complete >= n)
				return;
			else
				continue;
		}
		else if (process[y][1] <= quantum) {//short burst time unfinished
			if (counterflag == 0)
				ftnew[counterflag] = process[y][1]+at[0]; //ft=bt+at
			else
				ftnew[counterflag] = ftnew[counterflag - 1] + process[y][1]; //ft=bt+ft_prev
			ft[countt] = ftnew[counterflag];
			process[y][1] = process[y][1] - process[y][1];//update bt
			pidholder[counterflag] = pid[y];
			process[y][0] = ftnew[counterflag];//update at
			counterflag++;
			complete++;
			bubble(process, n);//sort by at
			countt++;
			execute(process, n);
		}
		else {
			if (counterflag == 0)
				ftnew[counterflag] = quantum + at[0];
			else
				ftnew[counterflag] = quantum + ftnew[counterflag - 1];
			ft[countt] = ftnew[counterflag];
			process[y][1] = process[y][1] - quantum;//update bt
			process[y][0] = ftnew[counterflag];//update at
			pidholder[counterflag] = pid[y];
			counterflag++;
			bubble(process, n);//sort by at
			countt;
			execute(process, n);
		}
	}
}
int main() {
	int k, l, wsum = 0, tsum = 0;
	float wavg = 0.0, tavg = 0.0;
	cout << "No. of processes:";
	cin >> n;
	cout << "Enter pid values:\n";
	for (k = 0; k < n; k++) {
		cin >> pid[k];
	}
	cout << "Enter arrival time values:\n";
	for (k = 0; k < n; k++) {
		cin >> at[k];
	}
	cout << "Enter burst time values:\n";
	for (k = 0; k < n; k++) {
		cin >> bt[k];
	}
	cout << "Enter quantum:";
	cin >> quantum;
	for (i = 0; i < n; i++) {//assigning to matrix
		for (j = 0; j < 2; j++) {
			if (j == 0)
				process[i][j] = at[i];
			else
				process[i][j] = bt[i];
		}
	}
	bubble(process, n);//sorts according to arrival time
	execute(process, n);//updates bts
	cout << endl;
	cout << "PID    " << "AT    " << "BT    " << "FT    " << "   TAT    " << "   WT    " << endl;
	for (l = 0; l < n; l++) {
		tat[l] = ft[l] - at[l];
		wt[l] = tat[l] - bt[l];
		cout << pid[l] << "       " << at[l] << "      " << bt[l] << "      " << ft[l] << "       " << tat[l] << "      " << wt[l] << endl;
	}
	//averages
	for (l = 1; l < n + 1; l++) {
		wsum += wt[l - 1];
	}
	for (l = 1; l < n + 1; l++) {
		tsum += tat[l - 1];
	}
	wavg = (float)wsum / n;
	tavg = (float)tsum / n;
	cout << "Average waiting time is " << wavg << endl;
	cout << "Average turn around time is " << tavg << endl;
	//Gantt chart
	for (l = 0; l < counterflag; l++) {
		int x;
		if (l != 0)
			x = ftnew[l] - ftnew[l - 1];
		else
			x = ftnew[l];
		cout << "|" << pidholder[l];
		while (x > 0) {
			cout << '-';
			x--;
		}
	}
	cout << "|";
	_getch();
}
