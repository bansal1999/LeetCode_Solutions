# Write your MySQL query statement below
select firstName, LastName, City, State
from person left join address
on Person.PersonID = Address.PersonId
