// 数据访问对象(DAO)
#include <iostream>
using namespace std;
class Employee {};
class SQLServerEmployee {
public:
	void insert (
		Employee const& employee) const {
		cout << "在SQLServer数据库中"
			"插入员工记录..." << endl;
	}
	Employee select (int id) const {
		cout << "在SQLServer数据库中"
			"查询员工记录..." << endl;
	}
};
class OracelEmployee {
public:
	void insert (
		Employee const& employee) const {
		cout << "在Oracel数据库中"
			"插入员工记录..." << endl;
	}
	Employee select (int id) const {
		cout << "在Oracel数据库中"
			"查询员工记录..." << endl;
	}
};
void sqlClient (void) {
	SQLServerEmployee sqlEmployee;
	Employee employee;
	sqlEmployee.insert (employee);
	employee = sqlEmployee.select (123);
}
void oraClient (void) {
	OracelEmployee oraEmployee;
	Employee employee;
	oraEmployee.insert (employee);
	employee = oraEmployee.select (123);
}
int main (void) {
	sqlClient ();
	oraClient ();
	return 0;
}
