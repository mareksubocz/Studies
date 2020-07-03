import React from 'react';
import NewTask from './NewTask';
import Filter from './Filter';

function ToDoList(props) {

    return(
        <div className="todolist">
            <Filter onFilterChange={props.onFilterChanged}/>
            
            <hr width="500px"/>

            {props.tasks}

            <hr width="500px"/>

            <NewTask/>
        </div>
        
    )
}

export default ToDoList