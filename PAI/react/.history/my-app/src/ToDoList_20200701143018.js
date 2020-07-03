import React from 'react';
import Task from './Task';
import NewTask from './NewTask';

function ToDoList(props) {
    const tasks = props.tasks.map(task => <Task key={task.id} text = {task.text}/>)
    return(
        <div className="todolist">
            <Task key="filter" text="hide completed"/>
            
            <hr width="500px"/>

            {tasks}

            <hr width="500px"/>

            <NewTask/>
        </div>
        
    )
}

export default ToDoList