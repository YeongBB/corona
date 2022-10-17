#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<algorithm>

#define fia 8

using namespace std;

class Corona_World
{

	friend int main();

private:
	char country[20] = { 0, };
	int occur = 0;
	int death = 0;
	double death_num = 0.0;

public:

	int in()						// 번호 입력
	{
		int Num;
		char Num_c[10];
		while (1)
		{
			cout << "번호를 선택하세요(1 ~ 8)" << endl;
			cin >> Num_c;
			Num = atoi(Num_c);
			if (Num <= 0 || Num > 8)
			{
				cout << "다시 " << endl;
			}
			else
			{
				Num -= 1;
				break;
			}
		}
		return Num;
	}
	void input()							//저장용
	{
		cout << "나라 정보를 입력하세요" << endl;
		cin >> country;
		cout << "확진자 수를 입력하세요" << endl;
		cin >> occur;
		cout << "사망자 수를 입력하세요" << endl;
		cin >> death;
		while (death > occur)
		{

			cout << "사망자가 수는 확진자 수보다 낮습니다. 다시 입력해주세요" << endl;
			cin >> death;
		}
		death_num = death * 100. / occur;
	}
	void see(vector<Corona_World>& list)			//출력
	{
		vector<Corona_World> copy_(fia);
		cout.precision(2);
		char in_[10];
		int num;
		for (int cg = 0; cg < fia; cg++)
		{
			strcpy_s(copy_[cg].country, sizeof(copy_[cg].country), list[cg].country);
			copy_[cg].occur = list[cg].occur;
			copy_[cg].death = list[cg].death;
			copy_[cg].death_num = list[cg].death_num;

		}
		while (1)
		{
			cout << "번호를 선택하세요" << endl;
			cout << "1.순차보기     2.지역명 순     3.확진자 수     4.사망자 순     5.사망률 순" << endl;
			cout << "============================================================================" << endl;

			cin >> in_;
			num = atoi(in_);
			if (num <= 0 || num > 5)
			{
				cout << "다시 ";
			}
			else
			{
				break;
			}
		}
		cout << "============================================================================" << endl;
		switch (num)
		{
		case 1:

			for (int i = 0; i < fia; i++)
			{
				cout << i + 1 << ".\t\t " << copy_[i].country << "\t\t " << copy_[i].occur << "\t\t " << copy_[i].death << "\t\t " << copy_[i].death_num << "%" << endl;
			}
			cout << "============================================================================" << endl;
			break;

		case 2:
			//sort(copy_[0].country), copy_[fia].country); // <--- 이것이 실행이 안됩니다.. 어쩔 수 없이 버블정렬 사용합니다..피드백 부탁드립니다.

			for (int i = 0; i < 7; i++)
			{
				for (int j = i + 1; j < 8; j++)
				{
					if (copy_[i].country < copy_[j].country)
					{
						swap(copy_[i].country, copy_[j].country);
						swap(copy_[i].occur, copy_[j].occur);
						swap(copy_[i].death, copy_[j].death);
						swap(copy_[i].death_num, copy_[j].death_num);
						int a = strlen(copy_[i].country);
						if (copy_[i].country < copy_[j].country)
						{
							if (a == 0)
							{
								swap(copy_[j].country, copy_[i].country);
								swap(copy_[i].occur, copy_[j].occur);
								swap(copy_[i].death, copy_[j].death);
								swap(copy_[i].death_num, copy_[j].death_num);
							}
						}
					}
				}
			}
			for (int i = 0; i < fia; i++)
			{
				cout << i + 1 << ".\t\t " << copy_[i].country << "\t\t " << copy_[i].occur << "\t\t " << copy_[i].death << "\t\t " << copy_[i].death_num << "%" << endl;
			}
			cout << "============================================================================" << endl;
			break;

		case 3:
			//sort(copy_[0].occur, copy_[fia].occur,greater<int>());  마찬가지

			for (int i = 0; i < 7; i++)
			{
				for (int j = i + 1; j < 8; j++)
				{
					if (copy_[i].occur < copy_[j].occur)
					{
						swap(copy_[i].country, copy_[j].country);
						swap(copy_[i].occur, copy_[j].occur);
						swap(copy_[i].death, copy_[j].death);
						swap(copy_[i].death_num, copy_[j].death_num);
					}
				}
			}
			for (int i = 0; i < fia; i++)
			{
				cout << i + 1 << ".\t\t " << copy_[i].country << "\t\t " << copy_[i].occur << "\t\t " << copy_[i].death << "\t\t " << copy_[i].death_num << "%" << endl;
			}
			cout << "============================================================================" << endl;
			break;
		case 4:
			//sort(copy_[0].death, copy_[fia].death,greater<int>());  마찬가지

			for (int i = 0; i < 7; i++)
			{
				for (int j = i + 1; j < 8; j++)
				{
					if (copy_[i].death < copy_[j].death)
					{
						swap(copy_[i].country, copy_[j].country);
						swap(copy_[i].occur, copy_[j].occur);
						swap(copy_[i].death, copy_[j].death);
						swap(copy_[i].death_num, copy_[j].death_num);
					}
				}
			}
			for (int i = 0; i < fia; i++)
			{
				cout << i << ".\t\t " << copy_[i].country << "\t\t " << copy_[i].occur << "\t\t " << copy_[i].death << "\t\t " << copy_[i].death_num << "%" << endl;
			}
			cout << "============================================================================" << endl;
			break;
		case 5:
			//sort(copy_[0].death_num, copy_[fia].death_num,greater<double>());  마찬가지

			for (int i = 0; i < 7; i++)
			{
				for (int j = i + 1; j < 8; j++)
				{
					if (copy_[i].death_num < copy_[j].death_num)
					{
						swap(copy_[i].country, copy_[j].country);
						swap(copy_[i].occur, copy_[j].occur);
						swap(copy_[i].death, copy_[j].death);
						swap(copy_[i].death_num, copy_[j].death_num);
					}
				}
			}
			for (int i = 0; i < fia; i++)
			{
				cout << i + 1 << ".\t\t " << copy_[i].country << "\t\t " << copy_[i].occur << "\t\t " << copy_[i].death << "\t\t " << copy_[i].death_num << "%" << endl;
			}
			cout << "============================================================================" << endl;
			break;
		default:
			cout << "오류로 인한 종료 " << endl;
			break;
		}
	}
};

int main()
{
	vector<Corona_World> list(fia);

	Corona_World data_;

	int num;

	while (1)
	{
		cout << "       국가정보 추가 : y  보기 : s  삭제 : d  끝내기 : e" << endl;
		cout << "* 삭제를 원하시면 삭제하기전에 보기를 선택하여 보고 삭제해 주세요(순차)" << endl;
		cout << "============================================================================" << endl;
		char sel;
		cin >> sel;
		fflush(stdin);
		switch (sel)
		{
		case 'y':
			num = data_.in();
			list[num].input();
			break;

		case 's':

			data_.see(list);

			break;

		case 'd':

			int nnum;
			cout << "삭제할 ";
			nnum = data_.in();
			list[nnum] = data_;
			cout << nnum << "번 삭제 완료" << endl;
			cout << "============================================================================" << endl;

			break;
		case'e':
			return 0;

		default:
			cout << "다시 입력하세요" << endl;
			break;
		}
	}
}