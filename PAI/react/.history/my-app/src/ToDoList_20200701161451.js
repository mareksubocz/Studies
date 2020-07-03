import React from 'react';
import Task from './Task';
import NewTask from './NewTask';
import Filter from './Filter';

function ToDoList(props) {

    return(
        <div className="todolist">
            <Filter/>
            
            <hr width="500px"/>

            {props.tasks}

            <hr width="500px"/>

            <NewTask/>
        </div>
        
    )
}

export default ToDoList