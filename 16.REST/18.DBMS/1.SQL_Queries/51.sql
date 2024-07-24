--  Remove all the reversed number pain fm given
-- table .

-- A B 1,2<-32,1
-- I 2
-- 2 4
-- 23 3,2 t .
-- 3 2
-- u z % A
-- /
-- B

-- 6 15 2 4
-- 71 8 3 2


-- methods -
-- 1.Joins
-- 2 Co-related subqueries
select distinct salary from worker order by salary DESC LIMIT 5 --top5
select distinct salary from worker order by salary DESC LIMIT 4,1 --5th one


select salary from worker w1 --nth highest salary
where n-1 = (select COUNT(distinct w2.salary) from worker w2
 where w2.salary>=w1.salary)

--th = -1

-- n max salaries
 select salary from worker w1 
where n >= (select COUNT(distinct(w2.salary)) from worker w2
 where w2.salary>=w1.salary)

 --n  min
 select salary from worker w1 
where n >= (select COUNT(distinct(w2.salary)) from worker w2
 where w1.salary>=w2.salary)
