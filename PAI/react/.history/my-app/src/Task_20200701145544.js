import React, {useState} from 'react';

function Task(props) {

    const [zaliczone, setZaliczone] = useState(0);

    function handleChange(){
        setZaliczone(!zaliczone)
    }

    return ( 
        <div className="task">
            <input type = "checkbox" id={props.key} name={props.key} checked={zaliczone} onChange={handleChange}/>
            <label for={props.key}> {props.text}</label>
        </div>
        
    );
}

export default Task