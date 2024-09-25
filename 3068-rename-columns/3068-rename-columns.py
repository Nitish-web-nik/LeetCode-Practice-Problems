import pandas as pd

def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    # Define the mapping of old column names to new column names
    column_mapping = {
        'id': 'student_id',
        'first': 'first_name',
        'last': 'last_name',
        'age': 'age_in_years'
    }
    
    # Rename the columns using the mapping
    students_renamed = students.rename(columns=column_mapping)
    
    return students_renamed
