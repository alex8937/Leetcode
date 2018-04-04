import pandas as pd
from pathlib import Path
import numpy as np
from datetime import date
import math


magic_number = 1.8


def flatten(nums):
    if type(nums) == int:
        return [nums]
    ans = []
    for num in nums:
        ans += flatten(num)
    return ans

def put(schedule, problems, dat):
    date_offsets = [math.ceil(magic_number ** i) for i in range(10)]
    todo_days = dat + np.array([pd.DateOffset(days = date_offset) for date_offset in date_offsets])
    print(dat.strftime('%Y-%m-%d'), 'added')        
    if not schedule.loc[dat.strftime('%Y-%m-%d'), 'Problems']:
        schedule.loc[dat.strftime('%Y-%m-%d'), 'Problems'] = list(problems)
    else:
        cur = [schedule.loc[dat.strftime('%Y-%m-%d'), 'Problems']]
        for problem in problems:
            cur.append(problem)
        cur = set([int(n) for n in flatten(cur)])
        schedule.loc[dat.strftime('%Y-%m-%d'), 'Problems'] = list(cur)    
    
    for dat in todo_days:
        print(dat.strftime('%Y-%m-%d'), 'added')        
        if not schedule.loc[dat.strftime('%Y-%m-%d'), 'Todo']:
 
            schedule.loc[dat.strftime('%Y-%m-%d'), 'Todo'] = list(problems)
        else:
            cur = [schedule.loc[dat.strftime('%Y-%m-%d'), 'Todo']]
            for problem in problems:
                cur.append(problem)
            cur = set([int(n) for n in flatten(cur)])
            schedule.loc[dat.strftime('%Y-%m-%d'), 'Todo'] = list(cur)
    return schedule


def initialize():
    first_date = pd.to_datetime("2018-01-01", format='%Y-%m-%d').date()
    dates = first_date + np.array([pd.DateOffset(days = date_offset) for date_offset in range(365 * 3)])
    empty_lists = [[] for _ in dates]
    schedule = pd.DataFrame(data = {"Date" : dates, "Problems" : empty_lists, "Todo": empty_lists})
    schedule = schedule.set_index('Date')
    return schedule
    

def get_problems():
    try:
        adds = input("Input problems to add (separated by spaces): e.g. 234 or 3 13 23: \n").split()
        adds = [int(add) for add in adds]
    except ValueError:
        print("Sorry, I didn't understand that.")
        return get_problems()
    return adds

def get_date():
    try:
        dat = input("Input date (Enter for today): e.g. 2018-04-03: \n")
        if dat == "":
            dat = pd.to_datetime(date.today())
        else:
            dat = pd.to_datetime(dat, infer_datetime_format = True)
    except ValueError:
        print("Sorry, I didn't understand that.")
        return get_date()
    return dat

def pre_process(schedule):
    dummy_schedule = initialize()
    dummy_schedule = dummy_schedule.join(schedule, lsuffix='_a', rsuffix='_b')
    dummy_schedule['Problems_b'] = dummy_schedule['Problems_b'].apply(lambda x : [] if pd.isnull(x) else x)
    dummy_schedule['Todo_b'] = dummy_schedule['Todo_b'].apply(lambda x : [] if pd.isnull(x) else x)
    del dummy_schedule['Problems_a']
    del dummy_schedule['Todo_a']    
    del dummy_schedule['Date'] 
    dummy_schedule.rename(lambda x : x[:-2], axis='columns', inplace = True)
    return dummy_schedule

def post_process(schedule):
    schedule = schedule[(np.vectorize(len)(schedule["Problems"]) != 0) | (np.vectorize(len)(schedule["Todo"]) != 0)]
    return schedule

def work_flow():
    path_string = "./schedule.csv"
    my_file = Path(path_string)
    if not my_file.is_file():
        schedule = initialize()
        print("No current file. Created schedule.csv")
    else:
        schedule = pd.read_csv(path_string)
        schedule = schedule.set_index(pd.DatetimeIndex(schedule['Date']))
        print("Loaded" + "path_string")
        schedule = pre_process(schedule)
        schedule_copy = pd.DataFrame.copy(schedule)         
    schedule.Problems = schedule.Problems.apply(lambda x : x[1: -1])
    schedule.Problems = schedule.Problems.apply(lambda x : x.split(", ") if len(x) else [])  
    schedule.Problems = schedule.Problems.apply(lambda n : [int(x) for x in n] if len(n) else [])  
    schedule.Todo = schedule.Todo.apply(lambda x : x[1: -1])
    schedule.Todo = schedule.Todo.apply(lambda x : x.split(", ") if len(x) else [])  
    schedule.Todo = schedule.Todo.apply(lambda n : [int(x) for x in n] if len(n) else [])      
    while True:
        problems = get_problems()
        dat = get_date()
        if input("Enter to proceed, if you made some mistakes, press anykey to re-enter \n") == "":
            break
    schedule = put(schedule, problems, dat)
    schedule = post_process(schedule)
    if my_file.is_file(): 
        schedule_copy = post_process(schedule_copy)        
        schedule_copy.to_csv("./schedule_bak.csv")    
    schedule.to_csv(path_string)

def main():
    work_flow()

if __name__ == "__main__":
    main()        



    



