# Write your MySQL query statement below
SELECT sell_date, count(distinct product) as num_sold,
GROUP_CONCAT(distinct product order by product ASC) as products
FROM  ACTIVITIES
GROUP BY sell_date
order by sell_date ASC;
