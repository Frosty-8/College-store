import pandas as pd

def rename(students:pd.DataFrame)->pd.DataFrame:
    rename_dict={
        'id':'student_id',
        'first':'first_name',
        'last':'last_name',
        'age':'age_in_years'
    }
    return students.rename(columns=rename_dict)