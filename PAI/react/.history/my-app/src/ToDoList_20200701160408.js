import React from 'react';
import Task from './Task';
import NewTask from './NewTask';
import Filter from './Filter';

function ToDoList(props) {

    function onCheckboxChange(id){
        props.onCheckboxChange(id)
    }

    const tasks = props.tasks.map(task => <Task key={task.id} text = {task.text} zaliczone={task.zaliczone} onCheckboxChange={onCheckboxChange}/>)
    return(
        <div className="todolist">
            <Filter/>
            
            <hr width="500px"/>

            {tasks}

            <hr width="500px"/>

            <NewTask/>
        </div>
        
    )
}

export default ToDoList