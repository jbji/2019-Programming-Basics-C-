
#include<time.h>
#include<iostream>
#include<string>
using namespace std;
//��30
int noAI();
int inAI(int num);
int randNum(int rangeMin,int rangeMax)
{
    return static_cast<double>(rand())/(RAND_MAX+1)*(rangeMax-rangeMin+1)+rangeMin;
}
int main()
{
    int sum = 0;
    int choice = 0;
    int first = 0;
    int AI = 0;
    cout << "��30��Ϸ����ѡ��˭�ȿ�ʼ:\n1.Person\n2.PC" << endl;
    cin >> first;
    cout << "�Ƿ��AI:\n1.Close AI\n2.Open AI" << endl;
    cin >> AI;
    while(sum <= 30)
    {
        srand(time(NULL));//noAIʱ�������
        if(first == 1)
        {//������
            if(AI == 1)
            {//û��AI
                cout << "Person choice 1 or 2?:" << endl;
                cin >> choice;
                if(choice >2)
                {
                    cout << "ˣ����,Person lose!";
                    break;
                }
                sum += choice;
                if(sum == 30)
                {
                    cout << "Person win!" << endl;
                    break;
                }
                cout << "���ڵ���:" << sum << endl;
                int pc = noAI();
                cout << "pcѡ��" << pc << "��" << endl;
                sum += pc;
                if(sum >= 30)
                {
                    cout << "AI win!" << endl;
                    break;
                }
            }
            else
            {//��AI
                cout << "Person choice 1 or 2?:" << endl;
                cin >> choice;
                if(choice >2)
                {
                    cout << "ˣ����,Person lose!";
                    break;
                }
                sum += choice;
                if(sum == 30)
                {
                    cout << "Person win!" << endl;
                    break;
                }
                cout << "���ڵ���:" << sum << endl;
                int pc = inAI(sum);
                cout << "pcѡ��" << pc << "��" << endl;
                sum += pc;
                if(sum >= 30)
                {
                    cout << "AI win!" << endl;
                    break;
                }
            }
        }
        else
        {//�����
            if(AI == 1)
            {//û��AI
                int pc = noAI();
                sum += pc;
                if(sum >= 30)
                {
                    cout << "AI win!" << endl;
                    break;
                }
                cout << "PCѡ��" << pc << "��" << endl;
                cout << "���ڵ���:" << sum << endl;
                cout << "Person choice 1 or 2?:" << endl;
                cin >> choice;
                if(choice >2)
                {
                    cout << "ˣ����,Person lose!";
                    break;
                }
                sum += choice;
                if(sum == 30)
                {
                    cout << "Person win!" << endl;
                    break;
                }
            }
            else
            {//��AI
                int pc = inAI(sum);
                sum += pc;
                if(sum >= 30)
                {
                    cout << "AI win!" << endl;
                    break;
                }
                cout << "PCѡ��" << pc << "��" << endl;
                cout << "���ڵ���:" << sum << endl;
                cout << "Person choice 1 or 2?:" << endl;
                cin >> choice;
                if(choice >2)
                {
                    cout << "ˣ����,Person lose!";
                    break;
                }
                sum += choice;
                if(sum == 30)
                {
                    cout << "Person win!" << endl;
                    break;
                }
            }
        }
        cout << "���ڵ���:" << sum << endl;
    }
    return 0;
}
int noAI()
{
    return randNum(1,2);
}
int inAI(int num) {
    int choice = 0;
    if (num == 0)
        return noAI();
    if (num % 3 == 0) {
        return noAI();
    } else {
        while (num % 3 != 0) {
            num++;
            choice++;
        }
        return choice;
    }
}