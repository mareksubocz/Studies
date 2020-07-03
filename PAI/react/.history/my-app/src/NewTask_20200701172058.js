import React, { useState } from 'react';

function NewTask(props) {
    const [text, setText] = useState('')

    return ( 
        <div className="newtask">
            <input type = "text" name="filterinput" value={text} onChange={(event) => setText(event.target.value)}/>
            <button onClick={() => props.onNewTask(text)}>Add</button>
        </div>
    );
}

export default NewTask