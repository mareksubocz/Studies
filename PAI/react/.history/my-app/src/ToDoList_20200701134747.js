import React from 'react';
import Task from './Task';

function ToDoList(props) {
    const tasks = props.tasks.map(task => < Task text = { task.text }
        visible = true / > )

}

export default ToDoList