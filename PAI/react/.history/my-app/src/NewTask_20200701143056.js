import React from 'react';

function NewTask(props) {
    return ( 
        <div className="newtask">
            <input type = "text" name="filterinput"/>
            <button>Add</button>
        </div>
    );
}

export default NewTask