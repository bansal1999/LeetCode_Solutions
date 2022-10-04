
SELECT (SELECT DISTINCT salary 
FROM Employee order by salary desc 
LIMIT 1 OFFSET 1) as secondHighestSalary