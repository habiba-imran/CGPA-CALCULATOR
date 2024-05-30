#include<iostream>
using namespace std;
//FUNCTION TO CONVERT GRADE TO GPA
float gradetopoints(char grade)
{
	switch (grade)
	{
	case 'A':
		return 4.0;
	case 'B':
		return 3.0;
	case 'C':
		return 2.0;
	case 'D':
		return 1.0;
	case 'F':
		return 0.0;
	default:
		return 0.0;
	}
}
//FUNCTION TO CALCULATE GPA
float calculate_gpa(int num_subjects, char grades[], int credits[])
{
	float totalpoints = 0;
	float totalcredits = 0;
	for (int i = 0;i < num_subjects;i++)
	{
		float gradepoints = gradetopoints(grades[i]);
		totalpoints += gradepoints * credits[i];
		totalcredits += credits[i];
	}
	return totalpoints / totalcredits;
}
int main()
{
	cout << "GPA AND CGPA CALCULATOR!\n\n";

	const int max_num = 100;
	//GPA CALCULATOR
	int num_subjects;
	cout << "Enter the total number of sujects for the current semester: ";
	cin >> num_subjects;


	char grades[max_num];
	int credits[max_num];
	for (int i = 0;i < num_subjects;i++)
	{
		cout << "Enter grade for subject " << i + 1 << " (A, B, C, D, F): ";
		cin >> grades[i];
		cout << "Enter credit hours for subject " << i + 1 << ": ";
		cin >> credits[i];
	}
	float gpa = calculate_gpa(num_subjects, grades, credits);
	cout << "The GPA for current semester is " << gpa;
	cout << endl<< endl;
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	cout << endl;
	//CGPA CALCULATOR
	int previous_sem;
	cout << "Enter number of previous semesters: ";
	cin >> previous_sem;
	float previousgpa[max_num];
	float total_gpa_prev_sem = 0;

	for (int i = 0;i < previous_sem;i++)
	{
		cout << "Enter GPA for semester " << i + 1 << ": ";
		cin >> previousgpa[i];
		total_gpa_prev_sem += previousgpa[i];
	}
	float total_gpa = total_gpa_prev_sem + gpa;
	float cgpa = total_gpa / (previous_sem + 1);
	cout << endl;
	cout << "Your CGPA is: " << cgpa;
}