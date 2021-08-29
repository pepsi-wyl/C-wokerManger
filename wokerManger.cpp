
//@wyl  

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstring>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;
//void test() {           //密码及验证信息录入
//	fstream ofs("name.txt",ios::out);
//	fstream ofss("password.txt",ios::out);
//	fstream ofsss("check.txt", ios::out);
//	string name;
//	string password;
//	string check;
//	cin>>name;
//	cin>>password;
//	cin >> check;
//	ofs<<name;
//	ofss<<password;
//	ofsss << check;
//	ofs.close();
//	ofss.close();
//	ofsss.close();
//}
class lading {
	public:
		lading();
		~lading();   
		void welcome();                      //欢迎
		void byebye();                       //再见
		void Setname();                      //输入用户名
		void Setpassword();                  //输入密码
		void Setcheck();                     //输入验证信息
		void Setverify();                    //输入验证码
		void getverify();                              //得到验证码
		int ladingcheck(string L_name, string L_password,string L_verify,string g_verify);    //检查登陆函数
		void changepassword(string L_name, string L_check);       //更改密码函数
		string L_name;
		string L_password;
		string L_check;
		string L_verify;
		string g_verify;
};
lading::lading()  {  }
lading::~lading()   {  }
void lading::welcome() {
	cout << endl;
	system("date/t");
	system("time/t");
	cout << "                * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "                *                                               *" << endl;
	cout << "                *            欢迎使用zhazha职工管理系统         *" << endl;
	cout << "                *                                               *" << endl;
	cout << "                * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "                * *   1 登陆       2 忘记密码      0 退出程序 * *" << endl;
	cout << "                * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << endl;
}
void lading::byebye() {
	cout << endl;
	system("date/t");
	system("time/t");
	cout << "                * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "                *                                               *" << endl;
	cout << "                *            感谢使用zhazha职工管理系统         *" << endl;
	cout << "                *                                               *" << endl;
	cout << "                * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
}
void lading::Setname() {
	string name;
	cout << "     请输入name: ";
	cin >> name;
	L_name = name;
}
void lading::Setpassword() {
	string password;
	cout << "     请输入密码: ";
	cin >> password;
	L_password = password;
}
void lading::Setcheck() {
	string check;
	cout << "     请输入验证信息:";
	cin >> check;
	L_check = check;
}
void lading::Setverify() {
	string verify_;
	cout << "     请输入验证码:";
	cin >> verify_;
	L_verify = verify_;
}
int lading::ladingcheck(string L_name, string L_password,string L_verify,string g_verify) { //登陆函数
	fstream ofsn("name.txt", ios::in);
	if(!ofsn.is_open()) {
		cout<<"     name文件打开失败"<<endl;
		return 0;
	}
	fstream ofsp("password.txt", ios::in);
	if(!ofsp.is_open()) {
		cout<<"     password文件打开失败"<<endl;
		return 0;
	}
	string name;
	string password;
	ofsn >> name;
	ofsp >> password;
	ofsn.close();
	ofsp.close();         
	if (name == L_name && password == L_password) {
		if(L_verify==g_verify) {
			cout<<"     登陆成功!!!"<<endl;
			return 1;      //登陆成功
		} else {
			cout<<"     登陆失败!!!"<<endl;
			return 2;      //登陆失败
		}
	} else {
		cout<<"     登陆失败!!!"<<endl;
		return 2;      //登陆失败
	}
}
void lading::changepassword(string L_name, string L_check) {    //更改密码函数
	fstream ifsn("name.txt", ios::in);
	if(!ifsn.is_open()) {
		cout<<"     name文件打开失败"<<endl;
		return ;
	}
	fstream ifsc("check.txt",ios::in);
	if(!ifsc.is_open()) {
		cout<<"      check文件打开失败"<<endl;
		return ;
	}
	string name;
	string check;
	ifsn >> name;
	ifsc >> check;
	ifsn.close();
	ifsc.close();
	if(name==L_name && check==L_check) {
		cout<<"      验证信息正确!!!"<<endl;
step1:
		string password1;
		string password2;
		cout<<"     请输入新密码:"<<endl;
		cin>>password1;
		cout<<"     请再次输入密码:"<<endl;
		cin>>password2;
		if(password1==password2) {
			fstream ifsp("password.txt",ios::out);
			ifsp<<password1;
			cout<<"      密码更改成功!!!"<<endl;
			ifsp.close();
		} else {
			cout<<"       两次密码不同，请重新更改!!!"<<endl;
			goto step1;
		}
	} else {
		cout<<"      验证信息错误!!!"<<endl;
	}
}
void lading::getverify() {
	srand(time(0));         //防止伪随机数 时间复杂度
	int num;
	char eng[60]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char node[6];     //node[6]='\0';
	for(int i=0; i<6; i++) {
		num=rand()%60+0;
		node[i]=eng[num];  //验证码
	}
	node[6]='\0';
	g_verify=node;
}
class woker {        //工人类
	public:
		void set_id(int id) {    //职工号
			this->id=id;
		}
		void set_name(string name) { //姓名
			this->name=name;
		}
		void set_sex(string sex) {  //性别
			this->sex=sex;
		}
		void set_age(int age) {    //年龄
			this->age=age;
		}
		void set_phonenumber(string phonenumber) {    //手机号码
			this->phonenumber=phonenumber;
		}
		void set_department(string department) {     //部门
			this->department=department;
		}
		void set_ensure(int ensure) {   //医疗保险
			this->ensure=ensure;
		}
		void set_wage(int wage) {     //工资
			this->wage=wage;
		}
		void set_address(string address) {      //家庭住址
			this->address=address;
		}
		void set_code(int code) {     //邮编
			this->code=code;
		}
		int get_id() {
			return id;
		}
		string get_name() {
			return name;
		}
		string get_sex() {
			return sex;
		}
		int get_age() {
			return age;
		}
		string get_phonenumber() {
			return phonenumber;
		}
		string get_department() {
			return department;
		}
		int get_ensure() {
			return ensure;
		}
		int get_wage() {
			return wage;
		}
		string get_address() {
			return address;
		}
		int get_code() {
			return code;
		}
		woker *next;
	private:
		int id; //职工号
		string name;//姓名
		string sex;//性别
		int age;//年龄
		string phonenumber;//手机号码
		string department; //部门
		int ensure;//医疗保险
		int wage;//工资
		string address;//家庭住址
		int code; //邮编
};
class wokermanger:public woker {    //工人管理类
	public:
		woker *head;
		woker *tail;
		wokermanger(); //构造提供链表头
		~wokermanger();//析构
		void showmenu();//菜单
		void creatwoker();//录入职工信息
		void printwoker();//输出职工信息
		void deletewoker();//删除职工信息
		void conserve_information(); //保存职工信息
		void clear_information();//销毁所有职工信息
		void add_information();//将文件信息导入
		void insert_information();//插入信息
		void changwoker(); //改变职工信息
		void paixu_information();//信息排序
		void serachwoker();//查找职工信息
		void classificationwoker();//职工信息分类查看
};
void wokermanger::showmenu() {
	cout << endl;
	system("date/t");
	system("time/t");
	cout << "                * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "                *         0 退出管理程序                        *" << endl;
	cout << "                *         1 录入职工信息                        *" << endl;
	cout << "                *         2 插入职工信息                        *" << endl;
	cout << "                *         3 展示职工信息                        *" << endl;
	cout << "                *         4 删除职工信息                        *" << endl;
	cout << "                *         5 查找职工信息                        *" << endl;
	cout << "                *         6 统计职工信息                        *" << endl;
	cout << "                *         7 修改职工信息                        *" << endl;
	cout << "                *         8 职工工资排序                        *" << endl;
	cout << "                *         9 职工信息保存                        *" << endl;
	cout << "                *        10 职工信息清空                        *" << endl;
	cout << "                * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "                * *        请输入你的选择                     * *" << endl;
	cout << "                * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
}
wokermanger::wokermanger() {     //创建链表头
	head = new woker;    
	head->set_id(0);//职工号               //唯一性
	head->set_name("0");//姓名
	head->set_sex("0");//性别
	head->set_age(0);//年龄
	head->set_phonenumber("0");//电话号码
	head->set_department("0");//部门
	head->set_wage(0);	//工资
	head->set_ensure(0);//医疗保险金
	head->set_address("0");//家庭住址
	head->set_code(0);//邮编
	head->next=NULL;
	tail = head;
}
wokermanger::~wokermanger() {      //析构
}
void wokermanger::add_information() {        //从文件中读入数据
	fstream ifs("wokerinformation.txt",ios::in);
	if(!ifs.is_open()) {
		cout<<"     wokerinformation文件打开失败!!!"<<endl;
		return;
	}
	int id,age,wage,ensure,code,flag=0;
	string name,sex,phonenumber,department,address;
	while(ifs>>id) {          //id作为引子
		woker *p=new woker;
		ifs>>name>>sex>>age>>phonenumber>>department>>wage>>ensure>>address>>code;
		p->set_id(id);
		p->set_name(name);
		p->set_sex(sex);
		p->set_age(age);
		p->set_phonenumber(phonenumber);
		p->set_department(department);
		p->set_wage(wage);
		p->set_ensure(ensure);
		p->set_address(address);
		p->set_code(code);
		tail->next = p;       //尾插    
		p->next = NULL;
		tail = p;  //尾部更新
		flag=1;
	}
	if(flag==1)
		cout<<"     文件数据导入成功!!!"<<endl;
	else if(flag==0)
		cout<<"     文件数据导入失败!!!"<<endl;
	ifs.close();
}
void wokermanger::conserve_information() { //保存信息
	woker *p=head->next;
	fstream ofs("wokerinformation.txt",ios::out);
	while(p!=NULL) {
		ofs<<p->get_id()<<endl;//职工号
		ofs<<p->get_name()<<endl;//姓名
		ofs<<p->get_sex()<<endl;//性别
		ofs<<p->get_age()<<endl;//年龄
		ofs<<p->get_phonenumber()<<endl;//手机号码
		ofs<<p->get_department()<<endl;//部门
		ofs<<p->get_wage()<<endl;//工资
		ofs<<p->get_ensure()<<endl;//医疗保险
		ofs<<p->get_address()<<endl;//家庭住址
		ofs<<p->get_code()<<endl;//邮编
		p=p->next;
	}
	cout<<"     文件保存成功!!!"<<endl;
	ofs.close();
}
void wokermanger::clear_information() {    //销毁所有职工信息
	cout<<"     1 确定要删除所有职工信息    0 退出 "<<endl;
	int key;
	cin >> key;
	while (1) {
		//防止输入错误
		if (key>1 || key <0) {
			cout << "     输入错误,重新输入!!!" << endl;
			cin >> key;
		} else {
			break;
		}
	}    
	if(key==0) {
		return ;
	} else if(key==1) { //销毁链表
		woker *p,*q;
		p=head->next;  //   
		if(p==NULL) {
			cout<<"    职工链表为空,无需销毁!!!"<<endl;
			system("pause");
			return;
		}
		while(p) {
			q=p;
			p=p->next;
			free(q);   //销毁指针
		}
		head->next=NULL;
		tail=head;//   头和尾部跟新及指向
		q=p;
		cout<<"     职工信息删除完毕完毕!!!"<<endl;
	}
}
void wokermanger::printwoker() {    //展示信息
	int number=0;  //计数
	woker *p;  //操作指针
	p=head->next;
	if(p==NULL) {
		cout<<"职工链表为空!!!"<<endl;
		return;
	}
	while(p!=NULL) {
		cout<<"职工工号:"<<p->get_id()
		    <<"\t职工姓名:"<<p->get_name()
		    <<"\t职工性别:"<<p->get_sex()
		    <<"\t职工年龄:"<<p->get_age()
		    <<"\t职工手机号码"<<p->get_phonenumber()
		    <<"\t职工部门:"<<p->get_department()
		    <<"\t职工工资:"<<p->get_wage()
		    <<"\t职工医疗保险金:"<<p->get_ensure()
		    <<"\t职工家庭住址:"<<p->get_address()
		    <<"\t职工邮编:"<<p->get_code()
		    <<"\t"<<endl;
		p=p->next;
		++number;
	}
	cout<<"      共有:"<<number<<"名职工。"<<endl;
}
void wokermanger::creatwoker() {   //录入信息
	int count=0;
	cout << "\n      请输入职工总数:" << endl;
	cin >> count;
	while (1) { //防止输入错误
		if (count <= 0) {
			cout << "     输入错误,重新输入!!!" << endl;
			cin >> count;
		} else {
			break;
		}
	}
	for (int i = 1; i <= count; i++) {
		if(i!=1) {
			cout << "      继续请输入1   退出请输入0" << endl;
			int key;
			cin >> key;
			while (1) { //防止输入错误
				if (key>1 || key <0) {
					cout << "       输入错误,重新输入!!!" << endl;
					cin >> key;
				} else {
					break;
				}
			}
			if (key == 0) {
				return;
			}
		}
step2:
		int id,age,wage,ensure,code;
		string name,sex,phonenumber,department,address;
		woker *q=head->next;    //查找重复指针   
		woker *p=new woker;    //操作指针 
		cout << "      请输入职工号 :";
		cin>>id;
		p->set_id(id);
		cout << "      请输入姓名:";
		cin>>name;
		p->set_name(name);
		cout << "      请输入性别:";
		cin>>sex;
		p->set_sex(sex);
		cout << "      请输入年龄:";
		cin>>age;
		p->set_age(age);
		cout << "      请输入电话号码:";
		cin>>phonenumber;
		p->set_phonenumber(phonenumber);
		cout << "      请输入部门:";
		cin>>department;
		p->set_department(department);
		cout << "      请输入工资:";
		cin>>wage;
		p->set_wage(wage);
		cout << "      请输入医疗保险金:";
		cin>>ensure;
		p->set_ensure(ensure);
		cout << "      请输入家庭住址:";
		cin>>address;
		p->set_address(address)	;
		cout << "      请输入邮编:";
		cin>>code;
		p->set_code(code);
		int flag = 0;    //假设不存在
		while (q) {
			if (p->get_id() == q->get_id()) {
				flag = 1;    //存在
				break;
			} else {
				flag = 0;    //不存在
			}
			q = q->next;
		}
		if (flag == 1) {
			cout << "       职工工号信息存在，请重新录入!!!" << endl;
			free(p);
			goto step2;
		}
		tail->next = p;       //尾插
		p->next = NULL;
		tail = p;//尾部更新
		cout<<"    添加成功!!!"<<endl;
	}
}
void wokermanger::deletewoker() {     //删除信息
step3:
	woker *p=head;
	woker *q=p->next;  //删除指针  
	if (q==NULL) {
		cout << "     职工链表为空，删除失败!!!" << endl;
		return;
	}
	cout << "      请输入要删除职工的工号:" << endl;
	int id;
	cin >> id;
	int flag=0;
	while (q!=NULL) {
		if (q->get_id() == id) {
			if(q->next==NULL) { //删除尾部改变tail
				tail=p;
			}
			flag=1;//找到变1//备份信息
			fstream ofs("del_wokerinformation.txt",ios::app);
			ofs<<"职工号:"<<q->get_id()<<" 姓名:"<<q->get_name()<<" 性别:"<<q->get_sex()<<"年龄:"<<q->get_age()
			   <<" 电话号码:"<<q->get_phonenumber()<<" 部门:"<<q->get_department()<<" 工资:"<<q->get_wage()
			   <<" 医疗保险:"<<q->get_ensure()<<" 部门:"<<q->get_address()<<" 邮编:"<<q->get_code()<<endl;
			ofs.close();
			p->next = q->next;
			free(q);
			cout <<"     删除成功!!!" << endl;
			cout <<"     1继续删除 0退出删除" <<endl;
			break;
		} else {
			p = p->next;
			q = q->next;
		}
	}
	if(flag==0) {
		cout<<"      未找到该职工，删除失败!!!"<<endl;
		cout<<"      1重新删除 0退出删除"<<endl;
	}
	int key;
	cin >> key;
	while (1) { //防止输入错误
		if (key>1 || key <0) {
			cout << "      输入错误,重新输入!!!" << endl;
			cin >> key;
		} else {
			break;
		}
	}
	if (key == 0) {
		return;
	} else if(key==1) {
		goto step3;
	}
}
void wokermanger::changwoker() {     //改变信息
	woker *p=head->next;   //p为操作指针
	if (p==NULL) {
		cout << "     职工链表为空，查询失败失败!!!" << endl;
		return;
	}
	int id,age,wage,ensure,code,key,flag=0;
	string name,sex,phonenumber,department,address;
step4:
	cout<<"     请输入要改变职工的ID"<<endl;
	cin>>id;
	while(p) {
		if(p->get_id()==id) {
			flag=1;
			break; //找到该职工
		} else {//未找到该员工
			p=p->next;
		}
	}
	if(flag==0) {
		cout<<"     未找到该员工!!!"<<endl;
		cout<<"     1重新输入 0 退出查询"<<endl;
		cout<<"     输入数字实现功能"<<endl;
		cin >> key;
		while (1) {
			//防止输入错误
			if (key>1 || key <0) {
				cout << "      输入错误,重新输入!!!" << endl;
				cin >> key;
			} else {
				break;
			}
		}
		if (key == 0) {
			return;
		} else if(key==1) {
			p=head->next;
			goto step4;
		}
	} else {
		//找到该员工
		while(1) {
			system("pause");
			system("cls");
			system("date/t");
			system("time/t");
			cout<<"       * * * * * * * * * * *"<<endl;
			cout<<"       *0 退出更改         *"<<endl;
			cout<<"       *1 职工姓名更改     *"<<endl;
			cout<<"       *2 职工年龄更改     *"<<endl;
			cout<<"       *3 职工性别更改     *"<<endl;
			cout<<"       *4 职工手机号码更改 *"<<endl;
			cout<<"       *5 职工部门更改     *"<<endl;
			cout<<"       *6 职工工资更改     *"<<endl;
			cout<<"       *7 职工医疗保险更改 *"<<endl;
			cout<<"       *8 职工住址更改     *"<<endl;
			cout<<"       *9 职工邮编更改     *"<<endl;
			cout<<"       * * * * * * * * * * *"<<endl;
			cout<<"       *输入数字实现功能    "<<endl;
			cout<<"       * * * * * * * * * * *"<<endl;
			cin >> key;
			while (1) {
				//防止输入错误
				if (key>9 || key<0) {
					cout << "     输入错误,重新输入!!!" << endl;
					cin >> key;
				} else {
					break;
				}
			}
			switch(key) {
				case 1://姓名
					cout<<"     请输入职工新姓名!!!"<<endl;
					cin>>name;
					p->set_name(name);
					cout<<"     修改成功"<<endl;
					break;
				case 2://年龄
					cout<<"     请输入职工新年龄!!!"<<endl;
					cin>>age;
					p->set_age(age);
					cout<<"     修改成功"<<endl;
					break;
				case 3://性别
					cout<<"     请输入职工新性别!!!"<<endl;
					cin>>sex;
					p->set_sex(sex);
					cout<<"     修改成功"<<endl;
					break;
				case 4://手机号码
					cout<<"     请输入职工新手机号码!!!"<<endl;
					cin>>phonenumber;
					p->set_phonenumber(phonenumber);
					cout<<"     修改成功"<<endl;
					break;
				case 5://部门
					cout<<"     请输入职工新部门!!!"<<endl;
					cin>>department;
					p->set_department(department);
					cout<<"     修改成功"<<endl;
					break;
				case 6://工资
					cout<<"     请输入职工新工资!!!"<<endl;
					cin>>wage;
					p->set_wage(wage);
					cout<<"     修改成功"<<endl;
					break;
				case 7:  //医疗保险
					cout<<"     请输入职工新医疗保险!!!"<<endl;
					cin>>ensure;
					p->set_ensure(ensure);
					cout<<"     修改成功"<<endl;
					break;
				case 8://住址
					cout<<"     请输入职工新住址!!!"<<endl;
					cin>>address;
					p->set_address(address);
					cout<<"     修改成功"<<endl;
					break;
				case 9://邮编
					cout<<"     请输入职工新邮编!!!"<<endl;
					cin>>code;
					p->set_code(code);
					cout<<"     修改成功"<<endl;
					break;
				case 0://退出
					return ;
					break;
			}
		}
	}
}
void wokermanger::serachwoker() {            //查找
	woker *p=head->next;   //p为操作指针
	if (p==NULL) {
		cout << "      职工链表为空，查询失败失败!!!" << endl;
		return;
	}
	while(1) {
		system("pause");
		system("cls");
		system("date/t");
		system("time/t");
		cout<<"       * * * * * * * * * * *"<<endl;
		cout<<"       *0  退出查找         *"<<endl;
		cout<<"       *1  职工工号查找     *"<<endl;
		cout<<"       *2  职工姓名查找     *"<<endl;
		cout<<"       * * * * * * * * * * * * "<<endl;
		cout<<"       *输入数字实现功能"<<endl;
		cout<<"       * * * * * * * * * * * *"<<endl;
		int key;
		cin >> key;
		while (1) {
			//防止输入错误
			if (key>2 || key <0) {
				cout << "     输入错误,重新输入!!!" << endl;
				cin >> key;
			} else {
				break;
			}
		}
		int id,flag=0;
		string name;
		switch(key) {
			case 1://工号
				cout<<"     输入要查询的工号:"<<endl;	//查询工号
				cin>>id;
				while(p) {
					if(p->get_id()==id) {
						flag=1;
						cout<<"职工工号:"<<p->get_id()
						    <<"\t职工姓名:"<<p->get_name()
						    <<"\t职工性别:"<<p->get_sex()
						    <<"\t职工年龄:"<<p->get_age()
						    <<"\t职工手机号码"<<p->get_phonenumber()
						    <<"\t职工部门:"<<p->get_department()
						    <<"\t职工工资:"<<p->get_wage()
						    <<"\t职工医疗保险金:"<<p->get_ensure()
						    <<"\t职工家庭住址:"<<p->get_address()
						    <<"\t职工邮编:"<<p->get_code()
						    <<"\t"<<endl;
						break;
					} else {
						p=p->next;
						flag=0;
					}
				}
				if(flag==0) {
					cout<<"     该工号职工不存在!!!"<<endl;
				}
				p=head->next;  //指针归位
				break;
			case 2://姓名
				cout<<"     输入要查询的姓名:"<<endl;    //查询姓名
				cin>>name;
				while(p) {
					if(p->get_name()==name) {
						flag=1;      //输出及变为1
						cout<<"\t职工姓名:"<<p->get_name()
						    <<"职工工号:"<<p->get_id()
						    <<"\t职工性别:"<<p->get_sex()
						    <<"\t职工年龄:"<<p->get_age()
						    <<"\t职工手机号码"<<p->get_phonenumber()
						    <<"\t职工部门:"<<p->get_department()
						    <<"\t职工工资:"<<p->get_wage()
						    <<"\t职工医疗保险金:"<<p->get_ensure()
						    <<"\t职工家庭住址:"<<p->get_address()
						    <<"\t职工邮编:"<<p->get_code()
						    <<"\t"<<endl;
					}
					p=p->next;
				}
				if(flag==0) {
					cout<<"     该姓名不存在!!!"<<endl;
				}
				p=head->next;  //指针归位
				break;
			case 0:
				return ;
				break;
		}
	}
}
void wokermanger::insert_information() { //插入信息
	while(1) {
		int id,age,wage,ensure,code,flag1=0,flag2=0,flag3=0,key;
		string name,sex,phonenumber,department,address;
		woker *q=head;
		woker *p=head->next;   //p为操作指针
		woker *repeat=head->next;//查找重复指针
		woker *ptr=new woker;  //ptr为输入指针
		if(p==NULL) {
			cout<<"     现在职工链表为空，只能插入最前面!!!"<<endl;
			cout<<"     1 插入    0 退出插入  "<<endl;
			cout<<"     输入数字实现功能"<<endl;
			cin >> key;
			while (1) {
				//防止输入错误
				if (key>1 || key <0) {
					cout << "     输入错误,重新输入!!!" << endl;
					cin >> key;
				} else {
					break;
				}
			}
			if(key==0) {
				return;
			} else if(key==1) {
				goto step5;
			}
		}
		system("pause");
		system("cls");
		system("date/t");
		system("time/t");
		cout<<"* * * * * * * * * * * * * * *"<<endl;
		cout<<"*     0 退出插入            *"<<endl;
		cout<<"*     1 插入最前面          *"<<endl;
		cout<<"*     2 插入到某职工号后面  *"<<endl;
		cout<<"* * * * * * * * * * * * * * *"<<endl;
		cout<<"* 请输入相关数字以实现功能  *"<<endl;
		cout<<"* * * * * * * * * * * * * * *"<<endl;
		cin >> key;
		while (1) {
			//防止输入错误
			if (key>2 || key <0) {
				cout << "     输入错误,重新输入!!!" << endl;
				cin >> key;
			} else {
				break;
			}
		}
		switch(key) {
			case 1:
step5:
step6:
				cout << "      请输入职工号 :";
				cin>>id;
				ptr->set_id(id);
				cout << "      请输入姓名:";
				cin>>name;
				ptr->set_name(name);
				cout << "      请输入性别:";
				cin>>sex;
				ptr->set_sex(sex);
				cout << "      请输入年龄:";
				cin>>age;
				ptr->set_age(age);
				cout << "      请输入电话号码:";
				cin>>phonenumber;
				ptr->set_phonenumber(phonenumber);
				cout << "      请输入部门:";
				cin>>department;
				ptr->set_department(department);
				cout << "      请输入工资:";
				cin>>wage;
				ptr->set_wage(wage);
				cout << "      请输入医疗保险金:";
				cin>>ensure;
				ptr->set_ensure(ensure);
				cout << "      请输入家庭住址:";
				cin>>address;
				ptr->set_address(address);
				cout << "      请输入邮编:";
				cin>>code;
				ptr->set_code(code);
				while(repeat) {
					if(repeat->get_id()==ptr->get_id()) {
						flag1=1;
						break;
					}
					repeat=repeat->next;
				}
				if(flag1==1) {
					cout<<"     输入的职工号已经存在,请重新输入"<<endl;
					repeat=head->next;//指针归为
					flag1=0;
					goto step6;
				} else  if(flag1==0) {
					q->next=ptr;
					ptr->next=p;
					cout<<"     插入成功!!!"<<endl;
					if(p==NULL) {
						tail=ptr;               //插在最后对尾部进行跟新
					}
				}
				break;
			case 2:
step7:
				cout<<"     请输入要插入要在哪个工号后面插入信息"<<endl;
				cin>>id;
				while(p) {
					q=p;          //p和q永远在一起
					if(p->get_id()==id) { //找到id
						flag2=1;
						break;
					} else {
						p=p->next;
					}
				}
				if(flag2==1) { //p指针指向插入点 //找到id
step8:
					cout << "      请输入职工号 :";
					cin>>id;
					ptr->set_id(id);
					cout << "      请输入姓名:";
					cin>>name;
					ptr->set_name(name);
					cout << "      请输入性别:";
					cin>>sex;
					ptr->set_sex(sex);
					cout << "      请输入年龄:";
					cin>>age;
					ptr->set_age(age);
					cout << "      请输入电话号码:";
					cin>>phonenumber;
					ptr->set_phonenumber(phonenumber);
					cout << "      请输入部门:";
					cin>>department;
					ptr->set_department(department);
					cout << "      请输入工资:";
					cin>>wage;
					ptr->set_wage(wage);
					cout << "      请输入医疗保险金:";
					cin>>ensure;
					ptr->set_ensure(ensure);
					cout << "      请输入家庭住址:";
					cin>>address;
					ptr->set_address(address);
					cout << "      请输入邮编:";
					cin>>code;
					ptr->set_code(code);
					while(repeat) {
						if(repeat->get_id()==ptr->get_id()) {
							flag3=1;
							break;
						}
						repeat=repeat->next;
					}
					if(flag3==1) {
						cout<<"     输入的职工号已经存在,请重新输入"<<endl;
						repeat=head->next;//指针归为
						flag3=0;
						goto step8;
					} else  if(flag3==0) {
						q=p->next;
						p->next=ptr;
						ptr->next=q;
						cout<<"     插入成功!!!"<<endl;
						if(q==NULL) {
							tail=ptr;          //插在最后对尾部进行跟新
						}
					}
				} else if(flag2==0) {
					cout<<"     你要插的职工信息不存在!!!"<<endl;
					cout<<"     1 重新插入    0 退出插入  "<<endl;
					cout<<"     输入数字实现功能"<<endl;
					cin >> key;
					while (1) {
						//防止输入错误
						if (key>1 || key <0) {
							cout << "     输入错误,重新输入!!!" << endl;
							cin >> key;
						} else {
							break;
						}
					}
					if(key==0) {
						return;
					} else if(key==1) {
						p=head->next;
						goto step7;
					}
				}
				break;
			case 0:
				free(ptr);
				return;
				break;
		}
	}
}
void wokermanger::classificationwoker() {
	woker *p=head->next;   //p为操作指针
	if (p==NULL) {
		cout << "      职工链表为空，统计失败!!!" << endl;
		return;
	}
	while(1) {
		int age,wage,key,flag=0,count=0;
		string sex,department,address;
		system("pause");
		system("cls");
		system("date/t");
		system("time/t");
		cout<<"       * * * * * * * * * * *"<<endl;
		cout<<"       *0  退出统计         *"<<endl;
		cout<<"       *1  职工年龄统计     *"<<endl;
		cout<<"       *2  职工性别统计     *"<<endl;
		cout<<"       *3  职工部门统计     *"<<endl;
		cout<<"       *4  职工工资统计     *"<<endl;
		cout<<"       *5  职工住址统计     *"<<endl;
		cout<<"       * * * * * * * * * * * * "<<endl;
		cout<<"       *输入数字实现功能"<<endl;
		cout<<"       * * * * * * * * * * * *"<<endl;
		cin >> key;
		while (1) {
			//防止输入错误
			if (key>7 || key <0) {
				cout << "     输入错误,重新输入!!!" << endl;
				cin >> key;
			} else {
				break;
			}
		}
		switch(key) {
			case 1://年龄
				cout<<"     输入要统计的年龄:"<<endl;
				cin>>age;
				while(p) {
					if(p->get_age()==age) {
						flag=1;      //输出及变为1
						cout<<"职工年龄:"<<p->get_age()
						    <<"\t职工工号:"<<p->get_id()
						    <<"\t职工姓名:"<<p->get_name()
						    <<"\t职工性别:"<<p->get_sex()
						    <<"\t职工手机号码"<<p->get_phonenumber()
						    <<"\t职工部门:"<<p->get_department()
						    <<"\t职工工资:"<<p->get_wage()
						    <<"\t职工医疗保险金:"<<p->get_ensure()
						    <<"\t职工家庭住址:"<<p->get_address()
						    <<"\t职工邮编:"<<p->get_code()
						    <<"\t"<<endl;
						++count;
					}
					p=p->next;
				}
				if(flag==0) {
					cout<<"     该年龄不存在!!!"<<endl;
				}
				cout<<"      共有:"<<count<<"名职工。"<<endl;
				p=head->next;  //指针归位
				break;
			case 2://性别
				cout<<"     输入要统计性别:"<<endl;
				cin>>sex;
				while(p) {
					if(p->get_sex()==sex) {
						flag=1;      //输出及变为1
						cout<<"职工性别:"<<p->get_sex()
						    <<"\t职工工号:"<<p->get_id()
						    <<"\t职工姓名:"<<p->get_name()
						    <<"\t职工年龄:"<<p->get_age()
						    <<"\t职工手机号码"<<p->get_phonenumber()
						    <<"\t职工部门:"<<p->get_department()
						    <<"\t职工工资:"<<p->get_wage()
						    <<"\t职工医疗保险金:"<<p->get_ensure()
						    <<"\t职工家庭住址:"<<p->get_address()
						    <<"\t职工邮编:"<<p->get_code()
						    <<"\t"<<endl;
						++count;
					}
					p=p->next;
				}
				if(flag==0) {
					cout<<"     该性别不存在!!!"<<endl;
				}
				cout<<"      共有:"<<count<<"名职工。"<<endl;
				p=head->next;  //指针归位
				break;
			case 3://部门
				cout<<"     输入要统计部门:"<<endl;
				cin>>department;
				while(p) {
					if(p->get_department()==department) {
						flag=1;      //输出及变为1
						cout<<"职工部门:"<<p->get_department()
						    <<"\t职工工号:"<<p->get_id()
						    <<"\t职工姓名:"<<p->get_name()
						    <<"\t职工性别:"<<p->get_sex()
						    <<"\t职工年龄:"<<p->get_age()
						    <<"\t职工手机号码"<<p->get_phonenumber()
						    <<"\t职工工资:"<<p->get_wage()
						    <<"\t职工医疗保险金:"<<p->get_ensure()
						    <<"\t职工家庭住址:"<<p->get_address()
						    <<"\t职工邮编:"<<p->get_code()
						    <<"\t"<<endl;
						++count;
					}
					p=p->next;
				}
				if(flag==0) {
					cout<<"     该部门不存在!!!"<<endl;
				}
				cout<<"      共有:"<<count<<"名职工。"<<endl;
				p=head->next;  //指针归位
				break;
			case 4:// 工资
				cout<<"     输入要统计的工资:"<<endl;
				cin>>wage;
				while(p) {
					if(p->get_wage()==wage) {
						flag=1;      //输出及变为1
						cout<<"职工工资:"<<p->get_wage()
						    <<"\t职工工号:"<<p->get_id()
						    <<"\t职工姓名:"<<p->get_name()
						    <<"\t职工性别:"<<p->get_sex()
						    <<"\t职工年龄:"<<p->get_age()
						    <<"\t职工手机号码"<<p->get_phonenumber()
						    <<"\t职工部门:"<<p->get_department()
						    <<"\t职工医疗保险金:"<<p->get_ensure()
						    <<"\t职工家庭住址:"<<p->get_address()
						    <<"\t职工邮编:"<<p->get_code()
						    <<"\t"<<endl;
						++count;
					}
					p=p->next;
				}
				if(flag==0) {
					cout<<"     该工资不存在!!!"<<endl;
				}
				cout<<"      共有:"<<count<<"名职工。"<<endl;
				p=head->next;  //指针归位
				break;
			case 5:// 住址
				cout<<"     输入要统计的住址:"<<endl;
				cin>>address;
				while(p) {
					if(p->get_address()==address) {
						flag=1;      //输出及变为1
						cout<<"职工家庭住址:"<<p->get_address()
						    <<"\t职工工号:"<<p->get_id()
						    <<"\t职工姓名:"<<p->get_name()
						    <<"\t职工性别:"<<p->get_sex()
						    <<"\t职工年龄:"<<p->get_age()
						    <<"\t职工手机号码"<<p->get_phonenumber()
						    <<"\t职工部门:"<<p->get_phonenumber()
						    <<"\t工工资:"<<p->get_wage()
						    <<"\t职工医疗保险金:"<<p->get_ensure()
						    <<"\t职工邮编:"<<p->get_code()
						    <<"\t"<<endl;
						++count;
					}
					p=p->next;
				}
				if(flag==0) {
					cout<<"     该住址不存在!!!"<<endl;
				}
				cout<<"      共有:"<<count<<"名职工。"<<endl;
				p=head->next;  //指针归位
				break;
			case 0:
				return ;
				break;
		}
	}
}
void wokermanger::paixu_information() {      //排序
	woker *pq=head->next;
	if(pq==NULL) {
		cout<<"     职工链表为空，无需排序"<<endl;
		system("pause");
		return ;
	}
	int max=0,flag=0,max1=100000000;
	woker *q,*p;
	for(q=head->next; q!=NULL; q=q->next) {
		flag=0;
		for(p=head->next; p!=NULL; p=p->next) {
			if(p->get_wage()>max && p->get_wage()<max1 ) {
				max=p->get_wage();    //对最大值更新
				flag=1;
			}
		}
		max1=max;     //max1为本次最大
		max=0;        //重新找出第二大
		if(flag==1) {
			p=head->next;
			while(p) {
				if(p->get_wage()==max1) {
					cout<<"职工工资:"<<p->get_wage()
					    <<"\t职工工号:"<<p->get_id()
					    <<"\t职工姓名:"<<p->get_name()
					    <<"\t职工性别:"<<p->get_sex()
					    <<"\t职工年龄:"<<p->get_age()
					    <<"\t职工手机号码"<<p->get_phonenumber()
					    <<"\t职工部门:"<<p->get_department()
					    <<"\t职工医疗保险金:"<<p->get_ensure()
					    <<"\t职工家庭住址:"<<p->get_address()
					    <<"\t职工邮编:"<<p->get_code()
					    <<"\t"<<endl;
				}
				p=p->next;
			}
		}
	}
}
int main() {
	system("color f9");
	//test();
	lading lad;   //实例化对象     //登陆
	while(1) {
		lad.welcome();
		int n=3;
		string key1;
		cin>>key1;
		while (1) {
			if (key1[0] >= 48 && key1[0] <= 57 && key1.length() == 1) {
				break;
			} else {
				cout << "     输入的指令不正确,重新输入!!!" << endl;
				cin >> key1;
			}
		}
		switch(key1[0]) {
			case '1':         //登陆 1
				while(n--) {
					lad.Setname();
					lad.Setpassword();
					lad.getverify();
					cout<<"     验证码:   "<<     lad.g_verify;         //展示验证码
					lad.Setverify();
					if( lad.ladingcheck(lad.L_name,lad.L_password,lad.L_verify,lad.g_verify)==1 ) {

						goto step2; //成功后跳过
					} else {
						if(n==0) {
							system("pause");
							system("cls");
							lad.byebye();    //3次失败退出程序
							exit(0);
						}
					}
				}
				break;
			case '2':
				lad.Setname();
				lad.Setcheck();
				lad.changepassword(lad.L_name,lad.L_check);
				system("pause");
				system("cls");
				break;
			case '0':
				lad.byebye();
				exit(0);
				break;
			default:
				cout<<"      输入的指令不正确，请重新输入!!!"<<endl;;
				break;
		}
	}
step2:	//登陆成功
	wokermanger wm;
	wm.add_information();//文件导入信息
	while(1) {
		system("pause");
		system("cls");
		wm.showmenu();
		int key;
		cin>>key;
		while (1) {//防止输入错误
			if (key>10 || key<0) {
				cout << "     输入错误,重新输入!!!" << endl;
				cin >> key;
			} else {
				break;
			}
		}
		switch(key) {
			case 1://录入
				wm.creatwoker();
				break;
			case 2://插入
				wm.insert_information();
				break;
			case 3://展示
				wm.printwoker();
				break;
			case 4://删除
				wm.printwoker();
				wm.deletewoker();
				break;
			case 5://查找
				wm.serachwoker();
				break;
			case 6://分类
				wm.classificationwoker();
				break;
			case 7://修改
				wm.changwoker();
				break;
			case 8://排序
				wm.paixu_information();
				break;
			case 9://保存
				wm.conserve_information();
				break;
			case 10://清空
				wm.clear_information();
				cout<<"     1 文件清空 0 放弃"<<endl;
				cin>>key;
				while (1) {//防止输入错误
					if (key>1 || key<0) {
						cout << "     输入错误,重新输入!!!" << endl;
						cin >> key;
					} else {
						break;
					}
				}
				switch(key) {
					case 1:
						wm.conserve_information();
						cout<<"     文件成功清除!!!"<<endl;
						break;
					case 0:
						cout<<"     成功放弃!!!"<<endl;
						break;
				}
				break;
			case 0://退出
				system("pause");
				system("cls");
				lad.byebye();
				exit(0);
				break;
		}
	}
}








