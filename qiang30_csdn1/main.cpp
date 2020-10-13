
#include<time.h>
#include<iostream>
#include<string>
using namespace std;
//抢30
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
    cout << "抢30游戏，请选择谁先开始:\n1.Person\n2.PC" << endl;
    cin >> first;
    cout << "是否打开AI:\n1.Close AI\n2.Open AI" << endl;
    cin >> AI;
    while(sum <= 30)
    {
        srand(time(NULL));//noAI时随机种子
        if(first == 1)
        {//人类先
            if(AI == 1)
            {//没有AI
                cout << "Person choice 1 or 2?:" << endl;
                cin >> choice;
                if(choice >2)
                {
                    cout << "耍阴招,Person lose!";
                    break;
                }
                sum += choice;
                if(sum == 30)
                {
                    cout << "Person win!" << endl;
                    break;
                }
                cout << "现在点数:" << sum << endl;
                int pc = noAI();
                cout << "pc选择：" << pc << "点" << endl;
                sum += pc;
                if(sum >= 30)
                {
                    cout << "AI win!" << endl;
                    break;
                }
            }
            else
            {//有AI
                cout << "Person choice 1 or 2?:" << endl;
                cin >> choice;
                if(choice >2)
                {
                    cout << "耍阴招,Person lose!";
                    break;
                }
                sum += choice;
                if(sum == 30)
                {
                    cout << "Person win!" << endl;
                    break;
                }
                cout << "现在点数:" << sum << endl;
                int pc = inAI(sum);
                cout << "pc选择：" << pc << "点" << endl;
                sum += pc;
                if(sum >= 30)
                {
                    cout << "AI win!" << endl;
                    break;
                }
            }
        }
        else
        {//人类后
            if(AI == 1)
            {//没有AI
                int pc = noAI();
                sum += pc;
                if(sum >= 30)
                {
                    cout << "AI win!" << endl;
                    break;
                }
                cout << "PC选择：" << pc << "点" << endl;
                cout << "现在点数:" << sum << endl;
                cout << "Person choice 1 or 2?:" << endl;
                cin >> choice;
                if(choice >2)
                {
                    cout << "耍阴招,Person lose!";
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
            {//有AI
                int pc = inAI(sum);
                sum += pc;
                if(sum >= 30)
                {
                    cout << "AI win!" << endl;
                    break;
                }
                cout << "PC选择：" << pc << "点" << endl;
                cout << "现在点数:" << sum << endl;
                cout << "Person choice 1 or 2?:" << endl;
                cin >> choice;
                if(choice >2)
                {
                    cout << "耍阴招,Person lose!";
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
        cout << "现在点数:" << sum << endl;
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