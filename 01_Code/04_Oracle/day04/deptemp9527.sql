/* drop  table */
drop table dept9527 cascade constraint;
drop table emp9527  cascade constraint;
/* create table */
create table dept9527(
    id  number constraint dept9527_id_pk
      primary key,
    name varchar2(30)  
);
/* dml */
insert into dept9527 values(1,'test1');
insert into dept9527 values(2,'test2');
commit;
/* create table */
create table emp9527(
   id number constraint  emp9527_id_pk
     primary key,
   name varchar2(30),
   salary  number,
   dept_id  number  constraint 
     emp9527_dept_id_fk references 
     dept9527(id) /*on delete cascade */  
                  on delete set null
);
insert into emp9527 values(1,'ea',5000,1);
insert into emp9527 values(2,'eb',5500,1);
insert into emp9527 values(3,'ec',6000,1);
insert into emp9527 values(4,'ed',11000,2);
insert into emp9527 values(5,'ee',15000,2);
commit;
