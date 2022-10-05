# Write your MySQL query statement below
SELECT 
    customer_number 
FROM 
    orders
GROUP BY customer_number
order by count(*) DESC
LIMIT 1;
