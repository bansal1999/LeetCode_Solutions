# Write your MySQL query statement below
Select Email
from Person
Group by Email
Having count(Email) > 1;