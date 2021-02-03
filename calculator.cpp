#include <iostream>
#include <math.h>
#include <sstream>
#include <stack>
using namespace std;
int priority(char c)
{
    if(c<='9'&&c>='0'||c=='.')
        return 0;
    else
    {
        switch(c)
        {
        	case 'p':
        		return 114;
        	case 'e':
        		return 514;
        	case 'i':
        		return 1919;
        	case '+':
        	case '-':
        	    return 1;
        	    break;
        	case '*':
        	case '/':
        	    return 2;
        	    break;
        	case '^':
        	    return 3;
        	    break;
        	case '!':
        	    return 4;
        	    break;
       		case '(':
        	case ')':
           		return 5;
        }
    }
}

double jisuan(string sss)
{
	stack<double> num;
	double n=0,k=1.0,j,l,m,p;
	bool bf=true,in=false;
	num.push(0);
	//cout<<sss[sss.size()-1]<<endl;
	for(int i=0;i<sss.size();i++)
	{
		if(sss[i]<='9'&&sss[i]>='0')
		{
			if(bf) n=n*10+sss[i]-'0';
			else
			{
				k/=10;
				n+=k*(sss[i]-'0');
			}
			in=true;
		}
		else if(sss[i]=='.') bf=false;
		else
		{
			if(sss[i]==' ')
			{
				if(n!=0||in)
				{
					num.push(n);
					//cout<<n<<endl;
					n=0; k=1.0;
					bf=true; in=false;
				}
				continue;
			}
			//////////if(sss[i]=='-'&&(sss[i+1]==0||sss[i+1]>10)) 
			j=num.top();
			num.pop();
			if(sss[i]=='!')
			{
				p=1;
				for(m=2;m<=j;m++)
				p*=m;
				num.push(p);
			}
			else
			{
				l=num.top();
				num.pop();
				switch(sss[i])
				{
					case '+':
						num.push(l+j);
						break;
					case '-':
						num.push(l-j);
						break;
					case '*':
						num.push(l*j);
						break;
					case '/':
						num.push(l/j);
						break;
					case '^':
						num.push(pow(l,j));
				}
				//cout<<l<<sss[i]<<j<<endl;
			}
		}
	}
	return num.top();
}

double zhuanhuan(string expr)
{
	stack<char> oper;
	stringstream ss;
	int i,rank;
	for(i=0;i<expr.size();i++)
	{
		rank=priority(expr[i]);
		if(rank==114)
		{
			ss<<"3.14159";
			continue;
		}
		else if(rank==514)
		{
			ss<<"2.71828";
			continue;
		}
		else if(rank==1919) continue;
		else if(rank==0) ss<<expr[i];
		else if(expr[i]==')')
		{
			ss<<' ';
			while(oper.top()!='(')
			{
				ss<<oper.top();
				oper.pop();
			}
			oper.pop();
		}
		else
		{
			ss<<' ';
			if(oper.empty()) oper.push(expr[i]);
			else
			{
				while(priority(oper.top())>=rank&&oper.top()!='(')
				{
					ss<<oper.top();
					oper.pop();
					if(oper.empty()) break;
				}
				oper.push(expr[i]);
			}
		}
	}
	ss<<' ';
	while(!oper.empty())
	{
		ss<<oper.top();
		oper.pop();
	}
    //cout<<ss.str()<<endl;
	return jisuan(ss.str());
}

void chuli()
{
	int n,i,m;
	double ans,j,k,l;
	string expr,x,y,z,w;
	cout<<"π(pi)=3.14159,e=2.71828."<<endl;
	cout<<"输入变量个数(支持小于等于4个):"<<endl;
	cin>>n;
	if(n>0)
	{
		switch(n)
		{
			case 1:
				cout<<"输入x的值:"<<endl;
				cin>>x;
				break;
			case 2:
				cout<<"分别输入x,y的值:"<<endl;
				cin>>x; cin>>y;
				break;
			case 3:
			 	cout<<"分别输入x,y,z的值:"<<endl;
			 	cin>>x; cin>>y; cin>>z;
			 	break;
			case 4:
				cout<<"分别输入x,y,z,w的值:"<<endl;
				cin>>x; cin>>y; cin>>z; cin>>w;
		}
	}
	cout<<"输入表达式(支持+,-,*,/,(),^,! 运算):"<<endl;
	cin>>expr;
	i=0;
	if(x[0]=='-')
	{
		while(i<expr.size())
		{
			if(expr[i]=='x')
			{
				expr.insert(i+1,")");
				expr.insert(i,"(0-");
				i+=3;
			}
			i++;
		}
		x.erase(0,1);
	}
	i=0;
	if(y[0]=='-')
	{
		while(i<expr.size())
		{
			if(expr[i]=='y')
			{
				expr.insert(i+1,")");
				expr.insert(i,"(0-");
				i+=3;
			}
			i++;
		}
		y.erase(0,1);
	}
	i=0;
	if(z[0]=='-')
	{
		while(i<expr.size())
		{
			if(expr[i]=='z')
			{
				expr.insert(i+1,")");
				expr.insert(i,"(0-");
				i+=3;
			}
			i++;
		}
		z.erase(0,1);
	}
	i=0;
	if(w[0]=='-')
	{
		while(i<expr.size())
		{
			if(expr[i]=='w')
			{
				expr.insert(i+1,")");
				expr.insert(i,"(0-");
				i+=3;
			}
			i++;
		}
		w.erase(0,1);
	}
	for(i=expr.size()-1;i>=0;i--)
	{
		switch(expr[i])
		{
			case 'x':
				expr.erase(i,1);
				expr.insert(i,x);
				break;
			case 'y':
				expr.erase(i,1);
				expr.insert(i,y);
				break;
			case 'z':
				expr.erase(i,1);
				expr.insert(i,z);
				break;
			case 'w':
				expr.erase(i,1);
				expr.insert(i,w);
				break;
			case '(':
				if(expr[i+1]=='-')
				{
					expr.insert(i+1,"(0");
					m=i+4;
					while(priority(expr[m])==0||priority(expr[m])>10) m++;
					expr.insert(m,")");
				}
		}
	}
	//cout<<expr<<endl;
	cout<<zhuanhuan(expr)<<endl;
}

int main()
{
	chuli();
	return 0;
}
