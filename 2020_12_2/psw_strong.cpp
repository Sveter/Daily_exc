//#include <iostream>
//#include <string>
//using namespace std;
//
//int get_grade(string s)
//{
//	int res = 0;
//	int len = s.size();
//	// 判断长度
//	if (len <= 4)
//		res += 5;
//	else if (len >= 5 && len <=7)
//		res += 10;
//	else
//		res += 25;
//	// 判断字母
//	int angle_a = 0;
//	int angle_A = 0;
//	int num = 0;
//	int fuhao = 0;
//	for (int i = 0; i < len; i++) {
//		if (s[i] >= 'a' && s[i] <= 'z')
//			angle_a++;
//		else if (s[i] >= 'A' && s[i] <= 'Z')
//			angle_A++;
//		else if (s[i] >= '0' && s[i] <= '9')
//			num++;
//		else
//			fuhao++;
//	}
//	if (angle_A == 0 && angle_a == 0)
//		res += 0;
//	else if (angle_a == 0 || angle_A == 0)
//		res += 10;
//	else
//		res += 20;
//	// 判断数字
//	if (num == 0)
//		res += 0;
//	else if (num == 1)
//		res += 10;
//	else
//		res += 20;
//	// 判断符号
//	if (fuhao == 0)
//		res += 0;
//	else if (fuhao == 1)
//		res += 10;
//	else
//		res += 25;
//	// 加分项
//	if (num != 0 && angle_A != 0 && angle_a != 0 && fuhao != 0)
//		res += 5;
//	else if (num != 0 && (angle_A != 0 || angle_a != 0) && fuhao != 0)
//		res += 3;
//	else if (num != 0 && (angle_A != 0 || angle_a != 0) && fuhao == 0)
//		res += 2;
//	return res;
//}
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	int grade = get_grade(str);
//	if (grade >= 90)
//		cout << "VERY_SECURE" << endl;
//	else if (80 <= grade < 90)
//		cout << "SECURE" << endl;
//	else if (70 <= grade < 80)
//		cout << "VERY_STRONG" << endl;
//	else if (60 <= grade < 70)
//		cout << "STRONG" << endl;
//	else if (50 <= grade < 60)
//		cout << "AVERAGE" << endl;
//	else if (25 <= grade < 50)
//		cout << "WEAK" << endl;
//	else
//		cout << "VERY_WEAK" << endl;
//	return 0;
//}
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string password;
    while (getline(cin, password))
    {
        int score = 0;
        //密码长度得分
        if (password.size() <= 4) {
            score += 5;
        }
        else if (password.size() >= 8) {
            score += 25;
        }
        else {
            score += 10;
        }
        //字母、数字、符号统计
        int Alpha = 0, alpha = 0, number = 0, number_count = 0, ch = 0, ch_count = 0;
        for (int i = 0; i < password.size(); i++)
        {
            if (password[i] >= 'a' && password[i] <= 'z') {
                alpha = 1;
            }
            else if (password[i] >= 'A' && password[i] <= 'Z') {
                Alpha = 1;
            }
            else if (isdigit(password[i])) {
                number = 1;
                number_count++;
            }
            else {
                ch = 1;
                ch_count++;
            }
        }
        //字母得分
        if ((alpha == 1 && Alpha == 0) || (alpha == 0 && Alpha == 1)) {
            score += 10;
        }
        else if (alpha == 1 && Alpha == 1) {
            score += 20;
        }
        //数字得分
        if (number_count > 1) {
            score += 20;
        }
        else if (number) {
            score += 10;
        }
        //符号得分
        if (ch_count > 1) {
            score += 25;
        }
        else if (ch) {
            score += 10;
        }
        //奖励得分
        if (Alpha && alpha && number && ch) {
            score += 5;
        }
        else if ((Alpha || alpha) && number && ch) {
            score += 3;
        }
        else if ((Alpha || alpha) && number) {
            score += 2;
        }
        if (score >= 90) {
            cout << "VERY_SECURE" << endl;
        }
        else if (score >= 80) {
            cout << "SECURE" << endl;
        }
        else if (score >= 70) {
            cout << "VERY_STRONG" << endl;
        }
        else if (score >= 60) {
            cout << "STRONG" << endl;
        }
        else if (score >= 50) {
            cout << "AVERAGE" << endl;
        }
        else if (score >= 25) {
            cout << "WEAK" << endl;
        }
        else {
            cout << "VERY_WEAK" << endl;
        }
    }
    return 0;
}