import pandas as pd

def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    return weather.pivot_table(index='month', columns='city', values='temperature', aggfunc='max')


# def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
#     pivoted=weather.pivot(index='month',columns='city',values='temperature')
#     pivoted.reset_index(inplace=True)
#     pivoted.columns.name=None
#     return pivoted

# data = {
#     'city': ['Jacksonville', 'Jacksonville', 'Jacksonville', 'Jacksonville', 'Jacksonville',
#              'ElPaso', 'ElPaso', 'ElPaso', 'ElPaso', 'ElPaso'],
#     'month': ['January', 'February', 'March', 'April', 'May',
#               'January', 'February', 'March', 'April', 'May'],
#     'temperature': [13, 23, 38, 5, 34, 20, 6, 26, 2, 43]
# }

# weather=pd.DataFrame(data)

# pivoted_weather=pivotTable(weather)
# print(pivoted_weather)