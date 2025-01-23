import pandas as pd

def select(students:pd.DataFrame)->pd.DataFrame:
    return students[students['student_id']==101][['name','age']]