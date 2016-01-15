// 数据访问对象(DAO)
// 通过引入抽象降低业务逻辑和数据存储的耦合
// 通过增加工厂类型进一步降低业务逻辑和数据
// 存储的耦合
// ————简单工厂模式
#include <iostream>
using namespace std;
class Employee {};
class DaoEmployee {
public:
	virtual ~DaoEmployee (void) {}
	virtual void insert (
		Employee const& employee) const = 0;
	virtual Employee select (
		int id) const = 0;
};
class SQLServerEmployee : public DaoEmployee {
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
class OracelEmployee : public DaoEmployee {
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
class Department {};
class DaoDepartment {
public:
	virtual ~DaoDepartment (void) {}
	virtual void insert (
		Department const& department)const=0;
	virtual Department select (
		int id) const = 0;
};
class SQLServerDepartment :
	public DaoDepartment {
public:
	void insert (
		Department const& department) const {
		cout << "在SQLServer数据库中"
			"插入部门记录..." << endl;
	}
	Department select (int id) const {
		cout << "在SQLServer数据库中"
			"查询部门记录..." << endl;
	}
};
class OracelDepartment :
	public DaoDepartment {
public:
	void insert (
		Department const& department) const {
		cout << "在Oracel数据库中"
			"插入部门记录..." << endl;
	}
	Department select (int id) const {
		cout << "在Oracel数据库中"
			"查询部门记录..." << endl;
	}
};
class DaoFactory {
public:
	static DaoEmployee* createEmployee (
		string const& dbName) {
		if (dbName == "SQLServer")
			return new SQLServerEmployee;
		if (dbName == "Oracel")
			return new OracelEmployee;
		return NULL;
	}
	static DaoDepartment* createDepartment (
		string const& dbName) {
		if (dbName == "SQLServer")
			return new SQLServerDepartment;
		if (dbName == "Oracel")
			return new OracelDepartment;
		return NULL;
	}
};
void daoClient (string const& dbName) {
	DaoEmployee* daoEmployee =
		DaoFactory::createEmployee (dbName);
	Employee employee;
	daoEmployee->insert (employee);
	employee = daoEmployee->select (123);
	delete daoEmployee;
	DaoDepartment* daoDepartment =
		DaoFactory::createDepartment (dbName);
	Department department;
	daoDepartment->insert (department);
	department = daoDepartment->select (10);
	delete daoDepartment;
}
int main (void) {
	daoClient ("SQLServer");
	daoClient ("Oracel");
	return 0;
}
