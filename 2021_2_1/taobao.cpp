// write your code here cpp

#include<iostream>

using namespace std;

//������Ϊ��׼
int totalday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//������ - ÿ���µ�������
int totalMoney[12] = { 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62 };

//�жϸ��·��Ƿ�Ϊ����
bool Judge_IsPriNum(int month) {
    if (month == 2 || month == 3 || month == 5 || month == 7 ||
        month == 11) {
        return true;
    }
    return false;
}

//�жϸ�����Ƿ�Ϊ����
bool Judge_IsLeaYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) ||
        year % 400 == 0) {
        return true;
    }
    return false;
}

//�������day2 - day1����������
int Caclue_Day(int day1, int day2, int month) {
    //1 - 31�� ��31��    31 - 1 = 30 -- �ü�1
    int sum = day2 - day1 + 1;
    if (!Judge_IsPriNum(month)) {
        //������һ��׬2��
        sum += sum;
    }
    return sum;
}

//�������month2 - month1 ������������
int Caclue_Month(int month1, int month2, int year) {
    int sum = 0;
    for (int i = month1; i <= month2; ++i) {
        //�±�-1
        sum += totalMoney[i - 1];
        //2�� - ���� - ���1��
        if (i == 2 && Judge_IsLeaYear(year)) {
            sum += 1;
        }
    }
    return sum;
}

//�������year2 - year1 ������������
int Caclue_Year(int year1, int year2) {
    int sum = 0;
    for (int i = year1; i <= year2; ++i) {
        sum += Caclue_Month(1, 12, i);
    }
    return sum;
}

int main() {


    //������ܵ�������
    int year1, month1, day1;
    int year2, month2, day2;

    while (cin >> year1 >> month1 >> day1
        >> year2 >> month2 >> day2) {
        //���������� ���� �ǿո�ָ��� ����cin�Ϳ���
        int total_num = 0;

        if (year1 == year2) {
            //ͬһ���
            if (month1 == month2) {
                //ͬһ�·�     
                total_num = Caclue_Day(day1, day2, month1);
            }
            else {
                //��ͬ�·�
                //1���ȼ�������������·ݵ�����
                total_num += Caclue_Month(month1, month2, year1);
                //2��month1���²���һ�µ���������
                total_num += Caclue_Day(day1, totalday[month1 - 1], month1);
                //3��month2β�²���һ�µ���������
                total_num += Caclue_Day(1, day2, month2);
            }
        }
        else {
            //��ͬ���
            //1���ȼ��������������ݵ�����
            total_num += Caclue_Year(year1 + 1, year2 - 1);
            //2��year1��ݲ���һ�����·ݵ�����
            total_num += Caclue_Month(month1 + 1, 12, year1);
            //3��year2��ݲ���һ�����·ݵ�����
            total_num += Caclue_Month(1, month2 - 1, year2);
            //4��year1�����²���һ�µ�����
            total_num += Caclue_Day(day1, totalday[month1 - 1], month1);
            //5��year2��β�²���һ�µ�����
            total_num += Caclue_Day(1, day2, month2);
        }

        //���
        cout << total_num << endl;
    }
}