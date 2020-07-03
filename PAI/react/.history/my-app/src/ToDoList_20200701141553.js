import React from 'react';
import Task from './Task';

function ToDoList(props) {
    const tasks = props.tasks.map(task => <Task key={task.id} text = {task.text}/>)
    return(
        <div className="todolist">
            <hr width="200px"/>
            {tasks}
            <hr width="200px"/>
        </div>
    )
}

export default ToDoList