import pandas as pd

def rows(employees: pd.DataFrame,n:int=3)->pd.DataFrame:
    return employees.head(n)

data={
    "employee_id": [3, 90, 9, 60, 49, 43],
    "name": ["Bob", "Alice", "Tatiana", "Annabelle", "Jonathan", "Khaled"],
    "department": ["Operations", "Sales", "Engineering", 
                   "InformationTechnology", "HumanResources", "Administration"],
    "salary": [48675, 11096, 33805, 37678, 23793, 40454]
}

employees_df=pd.DataFrame(data)

result=rows(employees_df)
print(result)