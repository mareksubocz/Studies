import React from 'react';
import Task from './Task';

function ToDoList(props) {
    const tasks = props.tasks.map(task => <Task key={task.id} text = {task.text}/>)
    return(
        <div>
            
            <Task key="filter" text="hide completed"/>

            <div className="todolist">
                <hr width="500px"/>
                {tasks}
                <hr width="500px"/>
            </div>
        </div>
        
    )
}

export default ToDoList