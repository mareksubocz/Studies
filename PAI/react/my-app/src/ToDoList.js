import React from 'react';
import NewTask from './NewTask';
import Filter from './Filter';

function ToDoList(props) {

    return(
        <div className="todolist">
            <Filter onFilterChange={props.onFilterChange} filtered={props.filtered}/>
            
            <hr width="500px"/>

            {props.tasks}

            <hr width="500px"/>

            <NewTask onNewTask={props.onNewTask}/>
        </div>
        
    )
}

export default ToDoList