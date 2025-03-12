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








 

