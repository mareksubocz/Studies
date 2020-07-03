import React from 'react';
import Task from './Task';

function ToDoList(props) {
    const tasks = props.tasks.map(task => <Task key={task.id} text = {task.text}/>)
    return(
        <div className="todolist">
            <hl/>
            {tasks}
            <hl/>
        </div>
    )
}

export default ToDoList