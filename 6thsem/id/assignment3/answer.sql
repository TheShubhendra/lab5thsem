CREATE TABLE CUSTOMER (
    CUST_NO VARCHAR2(5) PRIMARY KEY,
    NAME VARCHAR2(100) NOT NULL,
    PHONE_NO VARCHAR2(15),
    CITY VARCHAR2(50) NOT NULL,
    CONSTRAINT CUST_NO_CHECK CHECK (CUST_NO LIKE 'C____')
)


CREATE TABLE ACCOUNT (
    ACCOUNT_NO VARCHAR2(5) PRIMARY KEY,
    TYPE VARCHAR2(2) CHECK (TYPE IN ('SB', 'FD', 'CA')), 
    BALANCE NUMBER CHECK (BALANCE < 10000000),  
    BRANCH_CODE VARCHAR2(5),
    CONSTRAINT FK_ACCOUNT_BRANCH FOREIGN KEY (BRANCH_CODE) REFERENCES BRANCH (BRANCH_CODE),
    CONSTRAINT ACCOUNT_NO_CHECK CHECK (ACCOUNT_NO LIKE 'A____') 
);


CREATE TABLE DEPOSITOR (
    CUST_NO VARCHAR2(5),
    ACCOUNT_NO VARCHAR2(5),
    PRIMARY KEY (CUST_NO, ACCOUNT_NO),
    CONSTRAINT FK_DEPOSITOR_CUSTOMER FOREIGN KEY (CUST_NO) REFERENCES CUSTOMER (CUST_NO),
    CONSTRAINT FK_DEPOSITOR_ACCOUNT FOREIGN KEY (ACCOUNT_NO) REFERENCES ACCOUNT (ACCOUNT_NO)
);



CREATE TABLE LOAN (
    LOAN_NO VARCHAR2(5) PRIMARY KEY,
    CUST_NO VARCHAR2(5),
    AMOUNT NUMBER CHECK (AMOUNT > 1000),  
    BRANCH_CODE VARCHAR2(5),
    CONSTRAINT FK_LOAN_CUSTOMER FOREIGN KEY (CUST_NO) REFERENCES CUSTOMER (CUST_NO),
    CONSTRAINT FK_LOAN_BRANCH FOREIGN KEY (BRANCH_CODE) REFERENCES BRANCH (BRANCH_CODE),
    CONSTRAINT LOAN_NO_CHECK CHECK (LOAN_NO LIKE 'L____') 
);

CREATE TABLE BRANCH (
    BRANCH_CODE VARCHAR2(5) PRIMARY KEY,
    BRANCH_NAME VARCHAR2(100) NOT NULL,
    BRANCH_CITY VARCHAR2(50) CHECK (BRANCH_CITY IN ('DELHI', 'MUMBAI', 'KOLKATA', 'CHENNAI'))
);

CREATE TABLE INSTALLMENT (
    INST_NO NUMBER(2) CHECK (INST_NO<10), 
    LOAN_NO VARCHAR2(5),
    INST_AMOUNT NUMBER NOT NULL,
    CONSTRAINT INSTALLMENT_PK PRIMARY KEY (INST_NO, LOAN_NO),
    CONSTRAINT FK_INSTALLMENT_LOAN FOREIGN KEY (LOAN_NO) REFERENCES LOAN (LOAN_NO)
);
 
select course_id , title, credits from course where dept_name in ('Physics', 'Music', 'Finance', 'Biology');

select * from instructor where name like 'K%' and salary>65000;

SELECT 
    name,
    dept_name,
    salary + salary*1.05 + salary*0.2 AS gross_salary,
    (salary + salary*1.05 + salary*0.2) - salary*0.3 AS net_salary
FROM 
    instructor;

select * from instructor where salary between 60000 and 80000;

select * from instructor where name like '_r%';


select name from instructor where dept_name='Comp. Sci.' order by salary desc;

update instructor set salary = salary + salary*0.15;

update instructor set salary = salary + salary*0.03 where dept_name='Comp. Sci.' and salary < 70000;

select salary * 12 as annual_salary from instructor;

update course set title='Game Theory' where title = 'Game Design';

update course set title='Game Theory' where title = 'Game Design';

delete from course where course_id like 'BIO%';


---------------------------2-----------------------
select avg(salary) from instructor where dept_name = 'Physics';

select dept_name, avg(salary) from instructor group by dept_name;

select id, name, dept_name from instructor where salary = (select max(salary) from instructor);


select count(1) from instructor where dept_name = 'Comp. Sci.';

select sum(credits) from course where dept_name = 'Comp. Sci.';

select count(*) , sum(salary) from instructor where dept_name in ('Physics', 'Comp. Sci.')


select sum(credits) from course where dept_name in ('Comp. Sci.', 'Biology');

select building, sum(budget) from building group by building;
select dept_name , COUNT(*) from instructor group by dept_name;
select dept_name , COUNT(*) as count from instructor group by dept_name order by count desc;

select semester, count(*) from teaches group by semester;
select dept_name from instructor group by dept_name having count(*)<2;

select dept_name, count(*) from instructor group by dept_name having count(*)>=2;

select dept_name, count(*) from instructor where dept_name!='Finance' group by dept_name having count(*)>=2;

select dept_name, count(*) from instructor where dept_name!='Finance' group by dept_name having count(*)>=2;


select max(salary) from instructor where dept_name='Comp. Sci.';

---------------------------3------------------------------

select INITCAP('shubhendra') From dual;
select substr('shubhendra', 2,5) From dual;
select length('Siksha O Anusandhan University') as len From dual;
select initcap(name) from instructor;
select name,substr(dept_name,1,3) from instructor;

SELECT EXTRACT(MONTH FROM date_of_join) FROM instructor;
SELECT TO_CHAR(date_of_join, 'DD/MM/YY') from instructor;
SELECT id, 
       ROUND(MONTHS_BETWEEN(SYSDATE, date_of_join)) AS experience_months
FROM instructor;


SELECT id,
       FLOOR(MONTHS_BETWEEN(SYSDATE, date_of_join) / 12) AS experience_years,
       MOD(ROUND(MONTHS_BETWEEN(SYSDATE, date_of_join)), 12) AS experience_months
FROM instructor;

select id, EXTRACT(day from date_of_join) from instructor;

select SYSDATE + 15 from dual;
select round(94204.27348, 2) from dual;
select 5 + power(8,9) from dual;
select power(6464312, 0.5) from dual;
select lower('HELLO ITER') from dual;
