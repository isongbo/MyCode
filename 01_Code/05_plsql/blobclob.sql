create directory utllobdir as 'd:'

create table blobtest(col1 BLOB);
create table clobtest(col1 CLOB);

-- insert BLOB
declare
     a_blob BLOB;
     bfile_name BFILE := BFILENAME('ULTLOBDIR','teslob.doc');
begin
     insert into blobtest values (empty_blob())
     returning col1 into a_blob;
     dbms_lob.fileopen(bfile_name);
     dbms_lob.loadfromfile(a_blob, bfile_name, dbms_lob.getlength(bfile_name));
     dbms_lob.fileclose(bfile_name);
     commit;
end;

-- update BLOB
declare
      a_blob BLOB;
      bfile_name BFILE := BFILENAME('ULTLOBDIR','log.txt');
begin
      update blobtest set col1=empty_blob() where rownum=1
      returning col1 into a_blob;
      dbms_lob.fileopen(bfile_name);
      dbms_lob.loadfromfile(a_blob, bfile_name, dbms_lob.getlength(bfile_name));
      dbms_lob.fileclose(bfile_name);
      commit;
end;

-- insert CLOB
create table clobtest(col1 CLOB);

declare
      a_clob CLOB;
      bfile_name BFILE := BFILENAME('ULTLOBDIR','teslob.doc');
begin
      insert into clobtest values (empty_clob())
      returning col1 into a_clob;
      dbms_lob.fileopen(bfile_name);
      dbms_lob.loadfromfile(a_clob, bfile_name, dbms_lob.getlength(bfile_name));
      dbms_lob.fileclose(bfile_name);
      commit;
end;

-- update CLOB
declare
      a_clob CLOB;
      bfile_name BFILE := BFILENAME('ULTLOBDIR','log.txt');
begin
      update clobtest set col1=empty_clob() where rownum=1
      returning col1 into a_clob;
      dbms_lob.fileopen(bfile_name);
      dbms_lob.loadfromfile(a_clob, bfile_name, dbms_lob.getlength(bfile_name));
      dbms_lob.fileclose(bfile_name);
      commit;
end;

通过查看lob字段的长度判断是否插入成功 bitsCN_com

select dbms_lob.getlength(col1) from blobtest;
select dbms_lob.getlength(col1) from clobtest; bbs.bitsCN.com